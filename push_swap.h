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
}	t_int;

typedef struct s_lowhi
{
	int		low;
	int		high;
}				t_lowhi;

int		max(int a, int b);

int		min(int a, int b, int c, int d);

void	swap(t_stack **lst, int out, int loud);

void	push(t_stack **lst_a, t_stack **lst_b, int out, int loud);

void	rotate(t_stack **lst_a, int out, int loud);

void	r_rotate(t_stack **lst, int out, int loud);

int		lst_len(t_stack *lst);

t_stack	*ft_lstcpy(t_stack *base); //mem alloc: check for leaks!

void	ft_lstclr(t_stack **list);

t_stack	*get_args(int argc, char **argv);

int		greed(int argc, t_stack **lsta, t_stack **lstb);

void	sorta(t_stack **lsta, t_stack **lstb, int argc);

void	rdy_b(t_stack **lsta, t_stack **lstb);

void	gen_case(int first, int last, t_stack **lsta);

void	sortb(t_stack **lst);

void	*algs(int argc, t_stack **lsta, t_stack **lstb);

int		bra(t_stack *lsta, t_stack *lstb);

int		get_pos_ind(t_stack **lsta, int len, t_int **ind);

int		cycle_through(t_stack *hold, t_stack *temp, int index, int len);

int		act_ind(t_stack *lsta, t_stack *lstb, int index, t_int *ind);

int		ind_deal(t_stack **lsta, t_stack **lstb, t_int *ind);

t_lowhi	hilow(t_stack **lsta);

int		*moves_to_a_2(t_stack *lsta, int index);

int		*moves_to_a(t_stack *lsta);

int		*moves_to_b(t_stack *lstb, int index, int *moves);

int		get_pos_grt(t_stack **lsta, int len, t_int **ind);

#endif
