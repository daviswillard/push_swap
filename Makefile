NAME 		= 		push_swap
CHECK 		= 		checker
LIBFT 		= 		libft.a
LIB_DIR 	= 		libft/
CFLAGS 		= 		-Wall -Wextra -Werror -MMD -O2
CC			=		cc
SRC_DIR		=		sources/
BNS_DIR		=		bonus/
GNL			=		get_next_line/
VPATH		=		$(SRC_DIR):$(BNS_DIR)

SRCS 		= 			main.c	args.c \
					push_utils.c algos.c \
					bra/sort_a.c bra/bra.c \
					bra/indexw.c bra/bra_utils.c \
					bra/get_acts.c bra/do_the_action.c \
					bra/get_pos_ind.c bra/moves_to_a.c \
					bra/get_pos_grt.c
BNS 		=		bonus_main.c bonus_args.c \
				bonus_push_utils.c bonus_algos.c bonus_check.c \
				$(BNS_DIR)$(GNL)get_next_line.c

OBJ_DIR		:=	build_files
OBJS 		=	$(patsubst %,$(OBJ_DIR)/%,$(SRCS:.c=.o))
DEP			=	$(OBJS:.o=.d)
BNS_OBJS 	= 	$(patsubst %,$(OBJ_DIR)/%,$(BNS:.c=.o))
BNS_DEP 	= 	$(BNS:.c=.d)

all: 		lib $(NAME)

lib:
				@$(MAKE) all -sC $(LIB_DIR)

bonus: lib $(CHECK)

$(OBJ_DIR)/%.o:	%.c
				@$(CC) -I$(LIBFT) -I. -Ibonus/ $(CFLAGS) -c $< -o $@
				@printf "\033[0;33mObject %-40.100s [\033[0;32m✔\033[0;33m]\r" $@

$(OBJS):		| $(OBJ_DIR)

$(OBJ_DIR):
				@mkdir $(OBJ_DIR)
				@mkdir $(OBJ_DIR)/bra
				@mkdir $(OBJ_DIR)/$(BNS_DIR)
				@mkdir $(OBJ_DIR)/$(BNS_DIR)$(GNL)

$(CHECK): $(BNS_OBJS)
				@$(CC) $(CFLAGS) $(BNS_OBJS) -L$(LIB_DIR) -lft -o $(CHECK)

$(NAME): $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -L$(LIB_DIR) -lft -o $(NAME)

clean:
				@$(MAKE) clean -sC $(LIB_DIR)
				@rm -rf $(OBJS) $(DEP) $(BNS_OBJS) $(BNS_DEP)
fclean: clean
				@$(MAKE) fclean -sC $(LIB_DIR)
				@rm -rf $(NAME) $(CHECK)  $(OBJ_DIR)
re: 			fclean all bonus

.PHONY: 		all lib bonus clean fclean re
-include		$(OBJS:.o=.d) $(BNS_OBJS:.o=.d)
