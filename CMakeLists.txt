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
        sources/greed.c
        sources/main.c
        sources/stkb.c
        libft/ft_putendl_fd.c
                )
