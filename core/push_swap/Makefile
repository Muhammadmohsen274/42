NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
      stack.c \
      stack_utils.c \
      operations_1.c \
      operations_2.c \
      operations_3.c \
      operations_4.c \
      simple_sort.c \
      medium_sort.c \
      complex_sort.c \
      adaptive_sort.c \
      utils.c \
      split.c \
      validation.c \
      parse.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
