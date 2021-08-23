NAME = push_swap
PRINTF = libftprintf.a
PRINTF_DIR = ./printf/
CFLAGS = -Wall -Wextra -Werror -MMD
SRCS = 	sources/main.c	sources/args.c \
		sources/push_utils.c
OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)
all: $(PRINTF) $(NAME)
.c.o:
	gcc $(CFLAGS) -c $< -o $@
$(PRINTF):
	$(MAKE) all -sC $(PRINTF_DIR)
$(NAME): $(OBJS)
	gcc $(CFLAGS) $(PRINTF_DIR)$(PRINTF) $(OBJS) -o $(NAME)
clean:
	$(MAKE) clean -sC $(PRINTF_DIR)
	rm -rf $(OBJS) $(DEP)
fclean: clean
	$(MAKE) fclean -sC $(PRINTF_DIR)
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
-include	$(OBJS:.o=.d)
