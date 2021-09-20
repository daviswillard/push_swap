/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bra_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:24:36 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/20 19:24:37 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../push_swap.h"

t_lowhi	hilow(t_stack **lsta)
{
	t_lowhi	edg;
	t_stack	*tmp;
	int		min;
	int		max;

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
