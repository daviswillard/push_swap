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

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b, int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return (a);
	else if (b <= a && b <= c && b <= d)
		return (b);
	else if (c <= b && c <= a && c <= d)
		return (c);
	else if (d <= b && d <= c && a >= d)
		return (d);
	else
		exit(1);
}

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
