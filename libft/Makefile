NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c		\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c	\
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_putchar_fd.c 			\
		ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c\
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
		ft_substr.c ft_tolower.c ft_toupper.c ft_putendl_fd.c ft_memset.c\

BONUS		=	

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

DEPS = $(OBJ:.o=.d) $(BONUS_OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJ) $(BONUS_OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME) bonus

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	touch bonus

re: fclean all

.PHONY: all clean fclean re bonus