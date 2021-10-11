/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:00:32 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/03 16:08:05 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "get_next_line/get_next_line.h"

void	get_push_swap(t_stack **lsta, t_stack **lstb);

void	swap_bon(t_stack **lst);

void	push_bon(t_stack **lst_a, t_stack **lst_b);

void	rotate_bon(t_stack **lst);

void	r_rotate_bon(t_stack **lst);

#endif
