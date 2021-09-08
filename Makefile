NAME = push_swap
LIBFT = libft.a
LIB_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror -MMD
SRCS = 	sources/main.c	sources/args.c \
		sources/push_utils.c sources/algos.c \
		sources/greed.c sources/stkb.c \
		sources/sort_a.c
OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)
all: $(LIBFT) $(NAME)
.c.o:
	gcc $(CFLAGS) -c $< -o $@
$(LIBFT):
	$(MAKE) all -C $(LIB_DIR)
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
