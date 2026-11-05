*This project has been created as part of the 42 curriculum by ymaati.*

# libft
# Description
This project is a recreation of a portion of the Libc functions and building them into a 
  custom library libft without the use of any external functions except for 
	while, if, write, malloc, and free. The goal is to learn how the libc functions work under the hood.
## Functions
the library **libft** contains the following:\
		a **struct**: s_list;\
		**character funtions**: ft_isalpha, ft_isdigit, ft_isalnum, ft_isprint, ft_toupper,
			ft_tolower, ft_isascii.\
		**String functions**: ft_strlen, ft_atoi, ft_strchr, ft_strrchr, ft_strlcat, ft_strlcpy,
			ft_strncmp, ft_strnstr.\
		**Memory function**: ft_bzero, ft_memset, ft_memchr, ft_memcpy, ft_memmove,ft_memcmp.\
		**Heap Allocation function**: ft_strdup, ft_calloc.\
		**string transformation functions**: ft_itoa, ft_split, ft_strjoin, ft_strtrim,
			ft_striteri, ft_substr, ft_strmapi.\
		**File output**: ft_putnbr_fd, ft_putchar_fd, ft_putstr_fd, ft_putendl_fd.\
		**Linked lists**: ft_lstsize, ft_lstlast, ft_lstnew, ft_lstadd_back, ft_lstadd_front,
			ft_lstiter, ft_lstdelone, ft_lstclear, ft_lstmap.

# Instructions
### how to install
you can download the repository into your device by cloning the repo with Git\
```shell
	git clone https://github.com/Yassine-MAATI/Libft.git
	cd Libft
```
## how to compile
the project comes with a Makefile to allow you to easily compile the library by running
- `make` or `make all` to compile the library automatically,
- `clean` to remove the object files, 
- `fclean` to remove both the object files and the library,
- `re` to remove both object files and library then recreate them.
- `make test` to run basic project tests from the `main.c` file.
# Resources
this project wouldn't have been possible without the help of:\
[Beej's Guide to C Programming](https://beej.us/guide/bgc/)\
[The C programming Language book](https://www.cs.sfu.ca/~ashriram/Courses/CS295/assets/books/C_Book_2nd.pdf)\
[Geeks for Geeks](https://www.geeksforgeeks.org/)\
as well as numerous pages on [stack overflow](https://stackoverflow.com)\
it should be said that AI was used in the project when online resources and peers could
not provide a satisfactory or clear enough anwser. Gemini Notebook
was also used to quickly search through resources and compile notes and mind maps.
