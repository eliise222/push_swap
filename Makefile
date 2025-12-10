NAME = push_swap.a
LIBFT_PATH = ./libft
LIBFT 		= $(LIBFT_PATH)/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC     =	main.c \ medium_alg.c \ newlst.c \ instructions/pa_pb.c			 \
			parsing.c \ instructions/ra_rb_rr.c \ instructions/rra_rrb_rrr.c \
			instructions/sa_sb_ss.c \ simplealg.c \ utils_parsing.c \ utils.c \
			ft_lstadd_back.c \ ft_lstadd_front.c \ ft_lstclear.c \ ft_lstdelone.c \
			ft_lstiter.c \ ft_lstlast.c \ ft_lstmap.c \ ft_lstnew.c \ ft_lstsize.c \

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o
$(NAME) :


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJ)


fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME) 

re: fclean all

.PHONY: all clean fclean re