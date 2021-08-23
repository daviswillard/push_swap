cmake_minimum_required(VERSION 3.20)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable  (
        push_swap sources/main.c
        printf/libft/ft_atoi.c
        printf/libft/libft.h
        printf/libft/ft_lstnew.c
        printf/libft/ft_lstadd_back.c
        printf/libft/ft_lstclear.c
        printf/libft/ft_isdigit.c
        printf/libft/ft_putstr_fd.c
        printf/libft/ft_strlen.c
        printf/libft/ft_split.c
        push_swap.h
        sources/args.c
        sources/push_utils.c
        sources/algos.c
                )
