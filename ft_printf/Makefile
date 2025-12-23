NAME = libftprintf.a

SRC = ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c ft_strlen.c ft_putstr_fd.c ft_putnbr_base.c ft_putunsnbr.c ft_putptr.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re