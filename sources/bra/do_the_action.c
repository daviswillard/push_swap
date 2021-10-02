/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:06:55 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/24 17:07:06 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
 * функции выполняют действия над стэками а и б в зависимости от режима
 * работы info[1] (см. файл get_acts.c)
 */
static void	do_the_act_2(t_stack **lsta, t_stack **lstb, int *info, t_int *ind)
{
	if (info[1] == 3 || info[1] == 4)
	{
		while (info[2]-- > 0)
		{
			r_rotate(lsta, 2, ind->loud);
			r_rotate(lstb, 2, 0);
		}
		while (info[3]-- > 0)
		{
			if (info[1] == 3)
				r_rotate(lsta, 0, ind->loud);
			else
				r_rotate(lstb, 1, ind->loud);
		}
	}
	if (info[1] == 5)
	{
		while (info[2]-- > 0)
			r_rotate(lsta, 0, ind->loud);
		while (info[3]-- > 0)
			rotate(lstb, 1, ind->loud);
	}
}

void	do_the_action(t_stack **lsta, t_stack **lstb, int *info, t_int *ind)
{
	if (!info[1] || info[1] == 1)
	{
		while (info[2]-- > 0)
		{
			rotate(lsta, 2, ind->loud);
			rotate(lstb, 2, 0);
		}
		while (info[3]-- > 0)
		{
			if (!info[1])
				rotate(lsta, 0, ind->loud);
			else
				rotate(lstb, 1, ind->loud);
		}
	}
	else if (info[1] == 2)
	{
		while (info[2]-- > 0)
			rotate(lsta, 0, ind->loud);
		while (info[3]-- > 0)
			r_rotate(lstb, 1, ind->loud);
	}
	else
		do_the_act_2(lsta, lstb, info, ind);
}
