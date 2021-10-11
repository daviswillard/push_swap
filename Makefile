NAME = push_swap
CHECK = checker
LIBFT = libft.a
LIB_DIR = libft/
CFLAGS = -Wall -Wextra -Werror -MMD -O2
SRCS = 	sources/main.c	sources/args.c \
		sources/push_utils.c sources/algos.c \
		sources/bra/sort_a.c sources/bra/bra.c \
		sources/bra/indexw.c sources/bra/bra_utils.c \
		sources/bra/get_acts.c sources/bra/do_the_action.c \
		sources/bra/get_pos_ind.c sources/bra/moves_to_a.c \
		sources/bra/get_pos_grt.c
BNS =	bonus/sources/bonus_main.c bonus/sources/bonus_args.c \
		   bonus/sources/bonus_push_utils.c bonus/sources/bonus_algos.c bonus/sources/bonus_check.c \
		   bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)
BNS_OBJS = ${BNS:.c=.o}
BNS_DEP = $(BNS:.c=.d)
all: lib $(NAME)
lib:
	$(MAKE) all -sC $(LIB_DIR)
bonus: lib $(CHECK)
.c.o:
	gcc $(CFLAGS) -c $< -o $@
$(CHECK): $(BNS_OBJS)
	gcc $(CFLAGS) $(BNS_OBJS) -L$(LIB_DIR) -lft -o $(CHECK)
$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) -L$(LIB_DIR) -lft -o $(NAME)
clean:
	$(MAKE) clean -sC $(LIB_DIR)
	rm -rf $(OBJS) $(DEP) $(BNS_OBJS) $(BNS_DEP)
fclean: clean
	$(MAKE) fclean -sC $(LIB_DIR)
	rm -rf $(NAME) $(CHECK)
re: fclean all
.PHONY: all lib bonus clean fclean re
-include	$(OBJS:.o=.d) $(BNS_OBJS:.o=.d)
