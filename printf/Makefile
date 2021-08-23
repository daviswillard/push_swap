NAME = libftprintf.a
LIBFT = libft.a
LIB_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror -MMD
SRCS = ./sources/ft_printf.c   ./sources/works.c \
		./sources/percent.c ./sources/int_case.c \
		./sources/character_case.c ./sources/string_case.c \
		./sources/sxtn_case.c ./sources/address.c \
		./sources/flags.c ./sources/flgs_works.c
OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)
all:  $(LIBFT) $(NAME)
.c.o:
	gcc $(CFLAGS) -c $< -o $@
$(LIBFT):
	$(MAKE) all -sC $(LIB_DIR)
	$(MAKE) bonus -sC $(LIB_DIR)
$(NAME): $(OBJS)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $?
clean:
	$(MAKE) clean -sC $(LIB_DIR)
	rm -rf $(OBJS) $(DEP)
fclean: clean
	$(MAKE) fclean -sC $(LIB_DIR)
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
-include	$(OBJS:.o=.d)