NAME = push_swap.a
LIBFT_PATH = ./libft
LIBFT 		= $(LIBFT_PATH)/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC     =	main.c \ medium_alg.c \ newlst.c \ pa_pb.c \ parsing.c \
			ra_rb_rr.c \ rra_rrb_rrr.c \ sa_sb_ss.c 				\
			simplealg.c \ utils_parsing.c \ utils.c 				\

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o
$(NAME)


%.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@


clean:
		make clean -C $(LIBFT_PATH)
        rm -f $(OBJ)

fclean: clean
		make clean -C $(LIBFT_PATH)
        rm -f $(NAME) 


re: fclean all

.PHONY: all clean fclean re
                                    