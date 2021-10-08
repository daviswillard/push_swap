/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:00:32 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/03 16:08:05 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_ind
{
	int	loud;
	int	val;
	int	ig;
}	t_int;

typedef struct s_lowhi
{
	int		low;
	int		high;
}				t_lowhi;

int		elem_index(int **array, int len);

int		minmax(int a, int b, int mnm);

int		min_val(int a, int b, int c, int d);

int		min_mode(int a, int b, int c, int d);

void	swap(t_stack **lst, int out, int loud);

void	push(t_stack **lst_a, t_stack **lst_b, int out, int loud);

void	rotate(t_stack **lst_a, int out, int loud);

void	r_rotate(t_stack **lst, int out, int loud);

int		lst_len(t_stack *lst);

t_stack	*ft_lstcpy(t_stack *base); //mem alloc: check for leaks!

void	ft_lstclr(t_stack **list);

t_stack	*get_args(int argc, char **argv);

void	*algs(t_stack **lsta, t_stack **lstb);

#endif