NAME = push_swap
LIBFT = libft.a
LIB_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror -MMD
SRCS = 	sources/main.c	sources/args.c \
		sources/push_utils.c sources/algos.c \
		sources/greed/greed.c sources/greed/stkb.c \
		sources/greed/sort_a.c sources/bra/bra.c \
		sources/bra/indexw.c sources/bra/bra_utils.c \
		sources/bra/get_acts.c sources/bra/get_pos_grt.c \
		sources/bra/get_pos_ind.c sources/bra/moves_to_a.c \
		sources/bra/do_the_action.c
OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)
all: $(LIBFT) $(NAME)
.c.o:
	gcc $(CFLAGS) -c $< -o $@
$(LIBFT):
	$(MAKE) all -sC $(LIB_DIR)
$(NAME): $(OBJS)
	gcc $(CFLAGS) $(LIB_DIR)$(LIBFT) $(OBJS) -o $(NAME)
clean:
	$(MAKE) clean -sC $(LIB_DIR)
	rm -rf $(OBJS) $(DEP)
fclean: clean
	$(MAKE) fclean -sC $(LIB_DIR)
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
-include	$(OBJS:.o=.d)
