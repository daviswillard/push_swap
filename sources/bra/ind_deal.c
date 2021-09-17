/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind_deal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:28:59 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/17 12:29:04 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static struct s_lowhi	hilow(t_stack **lsta)
{
	struct s_lowhi	edg;
	t_stack			*tmp;
	int				min;
	int				max;

	tmp = *lsta;
	min = tmp->index;
	max = tmp->index;
	while (tmp->next)
	{
		if (min > tmp->index)
			min = tmp->index;
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	edg.low = min;
	edg.high = max;
	return (edg);
}

int	ind_deal(t_stack **lsta, t_stack **lstb, t_int *ind)
{
	struct	s_lowhi edg;
	int				acts;
	int				*arr;

	arr = NULL;
	while (*lstb)
	{

	}
	return (acts);
}
