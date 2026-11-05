#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <malloc.h>
#include "libft.h"

/* --- MEMORY TRACKER (Hooks into malloc/free via linker --wrap) --- */
static int	g_alloc_count = 0;

void	*__real_malloc(size_t size);
void	__real_free(void *ptr);

void	*__wrap_malloc(size_t size)
{
	void	*ptr = __real_malloc(size);
	if (ptr)
		g_alloc_count++;
	return (ptr);
}

void	__wrap_free(void *ptr)
{
	if (ptr)
		g_alloc_count--;
	__real_free(ptr);
}

/* Checks if usable heap size is valid and not wildly over-allocated */
static int	check_size(void *ptr, size_t expected)
{
	size_t	usable;

	if (!ptr)
		return (0);
	usable = malloc_usable_size(ptr);
	return (usable >= expected && usable <= expected + 24);
}

/* --- DISPLAY HELPERS --- */
#define G "\033[0;32m"
#define R "\033[0;31m"
#define Y "\033[0;33m"
#define X "\033[0m"

static void	res(char *name, int ok, int mok)
{
	printf("%-16s: %s ", name, ok ? G"OK "X : R"KO "X);
	if (mok == 1)
		printf(G"MOK"X"\n");
	else if (mok == 0)
		printf(R"MKO"X"\n");
	else
		printf("\n");
}

/* --- CALLBACK HELPERS FOR PART 2 & 3 --- */
static char	mapi_f(unsigned int i, char c) { return (c + i); }
static void	iteri_f(unsigned int i, char *c) { *c += i; }
static void	lst_iter_f(void *p) { *(char *)p += 1; }
static void	*lst_map_f(void *p)
{
	char	*s = ft_strdup((char *)p);
	if (s)
		s[0] += 1;
	return (s);
}

static int	test_fd(void (*f)(int), char *expected)
{
	int		p[2];
	char	buf[64];
	ssize_t	n;

	pipe(p);
	f(p[1]);
	close(p[1]);
	n = read(p[0], buf, 63);
	close(p[0]);
	if (n >= 0)
		buf[n] = '\0';
	return (strcmp(buf, expected) == 0);
}

static void	fd_char(int fd) { ft_putchar_fd('A', fd); }
static void	fd_str(int fd) { ft_putstr_fd("42", fd); }
static void	fd_endl(int fd) { ft_putendl_fd("42", fd); }
static void	fd_nbr(int fd) { ft_putnbr_fd(-42, fd); }

int	main(void)
{
	char	b1[32];
	void	*p;
	char	**sp;
	t_list	*l1, *l2;
	int		m_ok;

	printf(Y"=== PART 1: LIBC FUNCTIONS ===\n"X);
	res("ft_isalpha", ft_isalpha('a') && !ft_isalpha('1'), -1);
	res("ft_isdigit", ft_isdigit('9') && !ft_isdigit('a'), -1);
	res("ft_isalnum", ft_isalnum('a') && ft_isalnum('1') && !ft_isalnum('!'), -1);
	res("ft_isascii", ft_isascii(0) && ft_isascii(127) && !ft_isascii(128), -1);
	res("ft_isprint", ft_isprint(' ') && !ft_isprint('\n'), -1);
	res("ft_strlen", ft_strlen("1337") == 4 && ft_strlen("") == 0, -1);

	ft_memset(b1, 'A', 5);
	res("ft_memset", memcmp(b1, "AAAAA", 5) == 0, -1);

	ft_bzero(b1, 3);
	res("ft_bzero", memcmp(b1, "\0\0\0AA", 5) == 0, -1);

	ft_memcpy(b1, "12345", 6);
	res("ft_memcpy", strcmp(b1, "12345") == 0, -1);

	strcpy(b1, "123456");
	ft_memmove(b1 + 2, b1, 4);
	res("ft_memmove", strcmp(b1, "121234") == 0, -1);

	res("ft_strlcpy", ft_strlcpy(b1, "hello", 3) == 5 && !strcmp(b1, "he"), -1);
	strcpy(b1, "hi");
	res("ft_strlcat", ft_strlcat(b1, "42", 5) == 4 && !strcmp(b1, "hi42"), -1);
	res("ft_toupper", ft_toupper('a') == 'A' && ft_toupper('1') == '1', -1);
	res("ft_tolower", ft_tolower('A') == 'a' && ft_tolower('1') == '1', -1);
	res("ft_strchr", ft_strchr("abc", 'b') && !ft_strchr("abc", 'x'), -1);
	res("ft_strrchr", strcmp(ft_strrchr("abca", 'a'), "a") == 0, -1);
	res("ft_strncmp", ft_strncmp("abc", "abd", 2) == 0 && ft_strncmp("abc", "abd", 3) < 0, -1);
	res("ft_memchr", ft_memchr("abc", 'b', 3) != NULL && !ft_memchr("abc", 'c', 2), -1);
	res("ft_memcmp", ft_memcmp("abc", "abd", 2) == 0 && ft_memcmp("abc", "abd", 3) < 0, -1);
	res("ft_strnstr", ft_strnstr("lorem ipsum", "ipsum", 11) != NULL && !ft_strnstr("lorem ipsum", "ipsum", 5), -1);
	res("ft_atoi", ft_atoi("  -42a") == -42 && ft_atoi("2147483647") == 2147483647, -1);

	g_alloc_count = 0;
	p = ft_calloc(4, 2);
	m_ok = check_size(p, 8);
	res("ft_calloc", p && memcmp(p, "\0\0\0\0\0\0\0\0", 8) == 0, (free(p), m_ok && g_alloc_count == 0));

	g_alloc_count = 0;
	p = ft_strdup("1337");
	m_ok = check_size(p, 5);
	res("ft_strdup", p && !strcmp(p, "1337"), (free(p), m_ok && g_alloc_count == 0));

	printf(Y"\n=== PART 2: ADDITIONAL FUNCTIONS ===\n"X);
	g_alloc_count = 0;
	p = ft_substr("hello 42", 6, 2);
	m_ok = check_size(p, 3);
	res("ft_substr", p && !strcmp(p, "42"), (free(p), m_ok && g_alloc_count == 0));

	g_alloc_count = 0;
	p = ft_strjoin("13", "37");
	m_ok = check_size(p, 5);
	res("ft_strjoin", p && !strcmp(p, "1337"), (free(p), m_ok && g_alloc_count == 0));

	g_alloc_count = 0;
	p = ft_strtrim("xx42xx", "x");
	m_ok = check_size(p, 3);
	res("ft_strtrim", p && !strcmp(p, "42"), (free(p), m_ok && g_alloc_count == 0));

	g_alloc_count = 0;
	sp = ft_split("  a b  ", ' ');
	m_ok = (g_alloc_count == 3 && sp && check_size(sp, 3 * sizeof(char *)));
	res("ft_split", sp && !strcmp(sp[0], "a") && !strcmp(sp[1], "b") && !sp[2],
		(free(sp[0]), free(sp[1]), free(sp), m_ok && g_alloc_count == 0));

	g_alloc_count = 0;
	p = ft_itoa(-2147483648LL);
	m_ok = check_size(p, 12);
	res("ft_itoa", p && !strcmp(p, "-2147483648"), (free(p), m_ok && g_alloc_count == 0));

	g_alloc_count = 0;
	p = ft_strmapi("abc", mapi_f);
	m_ok = check_size(p, 4);
	res("ft_strmapi", p && !strcmp(p, "ace"), (free(p), m_ok && g_alloc_count == 0));

	strcpy(b1, "abc");
	ft_striteri(b1, iteri_f);
	res("ft_striteri", strcmp(b1, "ace") == 0, -1);

	res("ft_putchar_fd", test_fd(fd_char, "A"), -1);
	res("ft_putstr_fd", test_fd(fd_str, "42"), -1);
	res("ft_putendl_fd", test_fd(fd_endl, "42\n"), -1);
	res("ft_putnbr_fd", test_fd(fd_nbr, "-42"), -1);

	printf(Y"\n=== PART 3: LINKED LISTS ===\n"X);
	g_alloc_count = 0;
	l1 = ft_lstnew(ft_strdup("a"));
	m_ok = check_size(l1, sizeof(t_list));
	res("ft_lstnew", l1 && !strcmp(l1->content, "a") && !l1->next, m_ok && g_alloc_count == 2);

	l2 = ft_lstnew(ft_strdup("b"));
	ft_lstadd_front(&l1, l2);
	res("ft_lstadd_front", l1 == l2 && !strcmp(l1->content, "b"), -1);
	res("ft_lstsize", ft_lstsize(l1) == 2, -1);
	res("ft_lstlast", ft_lstlast(l1) && !strcmp(ft_lstlast(l1)->content, "a"), -1);

	ft_lstadd_back(&l1, ft_lstnew(ft_strdup("c")));
	res("ft_lstadd_back", !strcmp(ft_lstlast(l1)->content, "c") && ft_lstsize(l1) == 3, -1);

	ft_lstiter(l1, lst_iter_f);
	res("ft_lstiter", !strcmp(l1->content, "c") && !strcmp(l1->next->content, "b"), -1);

	l2 = ft_lstmap(l1, lst_map_f, free);
	res("ft_lstmap", l2 && !strcmp(l2->content, "d") && ft_lstsize(l2) == 3, g_alloc_count == 12);

	ft_lstdelone(ft_lstnew(ft_strdup("x")), free);
	res("ft_lstdelone", 1, g_alloc_count == 12);

	ft_lstclear(&l1, free);
	ft_lstclear(&l2, free);
	res("ft_lstclear", l1 == NULL && l2 == NULL, g_alloc_count == 0);

	return (0);
}
