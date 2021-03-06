cmake_minimum_required(VERSION 3.20)
project(push_swap C)

set(
        CMAKE_C_STANDARD 99
        libft/libft.h
        push_swap.h
        bonus/checker.h
)

include_directories(
        bonus
        libft
        .
)
add_executable  (
        push_swap sources/main.c
        libft/ft_atoi.c
        libft/libft.h
        libft/ft_lstnew.c
        libft/ft_strjoin.c
        libft/ft_lstadd_back.c
        libft/ft_lstclear.c
        libft/ft_isdigit.c
        libft/ft_putstr_fd.c
        libft/ft_strlen.c
        libft/ft_split.c
        libft/ft_putnbr_fd.c
        libft/ft_strchr.c
        libft/ft_strdup.c
        libft/ft_strncmp.c
        libft/ft_putchar_fd.c
        push_swap.h
        sources/args.c
        sources/push_utils.c
        sources/algos.c
        sources/main.c
        libft/ft_putendl_fd.c
        libft/ft_calloc.c
        sources/bra/sort_a.c
        sources/bra/bra.c
        sources/bra/get_pos_ind.c
        sources/bra/indexw.c
        sources/bra/get_acts.c
        sources/bra/bra_utils.c
        libft/ft_bzero.c
        sources/bra/moves_to_a.c
        sources/bra/do_the_action.c
        sources/bra/get_pos_grt.c
        )
