NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INCLUDES = -Iincludes

SRC = srcs/ft_print_c.c srcs/ft_print_i_or_d.c \
	srcs/ft_print_p.c srcs/ft_print_percent.c \
	srcs/ft_print_s.c srcs/ft_print_u.c srcs/ft_print_x.c \
	srcs/ft_print_xx.c srcs/ft_printf.c srcs/utils.c srcs/ft_putchar_fd.c

OBJS = $(SRC:.c=.o)


all: $(NAME)


$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	$(RM) $(OBJS)


fclean: clean
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
