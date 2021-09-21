cmake_minimum_required(VERSION 3.20)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable  (
        push_swap sources/main.c
        libft/ft_atoi.c
        libft/libft.h
        libft/ft_lstnew.c
        libft/ft_lstadd_back.c
        libft/ft_lstclear.c
        libft/ft_isdigit.c
        libft/ft_putstr_fd.c
        libft/ft_strlen.c
        libft/ft_split.c
        push_swap.h
        sources/args.c
        sources/push_utils.c
        sources/algos.c
        sources/greed/greed.c
        sources/main.c
        sources/greed/stkb.c
        libft/ft_putendl_fd.c
        libft/ft_calloc.c
        sources/greed/sort_a.c
        sources/bra/bra.c
        sources/bra/get_pos_ind.c
        sources/bra/get_pos_grt.c
        sources/bra/indexw.c
        sources/bra/ind_deal.c
        sources/bra/bra_utils.c
        libft/ft_bzero.c
        sources/bra/moves_to_a.c)
