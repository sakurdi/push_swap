SRCS = parsing.c stack_magic.c stack_utils.c utils.c sort.c
OBJ = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
PRINTF_DIR = ft_printf/
PRINTF_LIB = $(addprefix $(PRINTF_DIR), libftprintf.a)
NAME= push_swap

all: printf $(NAME) 
$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $^ $(PRINTF_LIB) -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
printf:
	make -C $(PRINTF_DIR)
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
re: fclean all
