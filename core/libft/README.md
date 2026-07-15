This project has been created as part of the 42 curriculum by muali

# Description

Libft is a custom C library that recreates a set of standard C library functions along with additional utility functions that manipulate strings, memory, arrays, and linked lists. 
The goal of this project is to deeply understand how standard functions work internally by implementing them from scratch.

The project serves as a foundation for future C projects in the 42 curriculum.

## Instructions

To compile the project, execute the following command in your terminal:
```bash
make or make all: Compiles all mandatory source files into object files and builds libft.a.
make clean: removes all generated object files (.o) from the directory.
make fclean: removes all object files and the compiled library file (libft.a).
make re: fully rebuilds everything
This will generate the static library: libft.a

To use the library, include the header file in your C file:
#include "libft.h"

Then compile your program with Libft:
```bash
cc -Wall -Wextra -Werror main.c -L. -lft
```


### Library Content
Part 1 - Standard Libc Functions

Reimplementation of common C standard library functions:

ft_memset, ft_bzero, ft_memcpy, ft_memmove
ft_strlen, ft_strlcpy, ft_strlcat
ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr
ft_atoi
ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint
ft_calloc, ft_strdup

Part 2 - Additional Functions

Utility and string manipulation functions:

ft_substr
ft_strjoin
ft_strtrim
ft_split
ft_itoa
ft_strmapi
ft_striteri
ft_putchar_fd
ft_putstr_fd
ft_putendl_fd
ft_putnbr_fd

Part 3 - Linked List Functions

Custom linked list implementation:

ft_lstnew
ft_lstadd_front
ft_lstsize
ft_lstlast
ft_lstadd_back
ft_lstdelone
ft_lstclear
ft_lstiter
ft_lstmap

#### Resources

# References

`man` pages to understand the structure of libc functions
`42 Libft subject PDF`
`geeksforgeeks and stackoverflows`

## AI Usage

All implementations were developed based on personal understanding after reading official documentation (man pages) and discussing with peers. The AI was used only as an additional explanation tool, not as a replacement for learning or implementation.


