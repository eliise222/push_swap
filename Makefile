NAME = push_swap
BONUS_NAME = checker
LIBFT_PATH = ./libft
LIBFT 		= $(LIBFT_PATH)/libft.a
FT_PRINTF_PATH = ./libft/ft_printf
FT_PRINTF	= $(FT_PRINTF_PATH)/libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC	=	main.c newlst.c pa_pb.c mediumalg.c\
		parsing.c ra_rb_rr.c rra_rrb_rrr.c \
		sa_sb_ss.c simplealg.c utils_parsing.c utils.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \
		do_adaptive.c do_alg.c benchmark.c tiny_sort.c radix_utils.c \

OBJ = $(SRC:.c=.o)

BONUS_SRC =	checker_bonus.c \
			libft/get_next_line.c libft/get_next_line_utils.c \
			newlst.c parsing.c utils.c utils_parsing.c \
			ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c \
			ft_lstnew.c ft_lstsize.c benchmark.c radix_utils.c \
			pa_pb.c ra_rb_rr.c \
			rra_rrb_rrr.c sa_sb_ss.c \

BONUS_OBJ = $(BONUS_SRC:.c=.o)


all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(FT_PRINTF) -o $(BONUS_NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINTF_PATH)
	rm -rf $(OBJ) $(BONUS_OBJ)


fclean: clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(FT_PRINTF_PATH)
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
