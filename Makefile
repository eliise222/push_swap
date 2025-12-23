NAME = push_swap
LIBFT_PATH = ./libft
LIBFT 		= $(LIBFT_PATH)/libft.a
FT_PRINTF_PATH = ./ft_printf
FT_PRINTF	= $(FT_PRINTF_PATH)/libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

SRC     =	main.c medium_alg.c newlst.c instructions/pa_pb.c \
			parsing.c instructions/ra_rb_rr.c instructions/rra_rrb_rrr.c \
			instructions/sa_sb_ss.c simplealg.c utils_parsing.c utils.c \
			ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \
			utils_medium_alg.c split_number_list.c instructions_medium_alg.c \
			do_adaptive.c do_alg.c benchmark.c tiny_sort.c radix_utils.c \

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)
$(NAME) :


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINTF_PATH)
	rm -rf $(OBJ)


fclean: clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(FT_PRINTF_PATH)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
