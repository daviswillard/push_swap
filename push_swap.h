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

void	swap(t_stack **lst, int out);

void	push(t_stack **lst_a, t_stack **lst_b, int out);

void	rotate(t_stack **lst_a, int out);

void	r_rotate(t_stack **lst, int out);

t_stack	*get_args(int argc, char **argv);

int		greed(int argc, t_stack **lsta, t_stack **lstb);

int		lst_len(t_stack *lst);

void	rdy_b(t_stack **lstb, t_stack **lsta);

void	only_first(int numb, int first, t_stack **lsta, t_stack **lstb);

void	gen_case(int first, int last, t_stack **lsta, t_stack **lstb);

void	*algs(int argc, t_stack **lsta, t_stack **lstb);

#endif
