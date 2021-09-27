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

int	elem_index(int **array, int len)
{
	int	value;
	int	index;
	int	ret;

	value = 0x7fffffff;
	ret = -1;
	index = 0;
	while (index < len)
	{
		if (value > array[index][0])
		{
			value = array[index][0];
			ret = index;
		}
		index++;
	}
	return (ret);
}

int	minmax(int a, int b, int mnm)
{
	if (!mnm)
	{
		if (a > b)
			return (b);
		else
			return (a);
	}
	else
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
}

int	min_val(int a, int b, int c, int d)
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

int	min_mode(int a, int b, int c, int d)
{
	if (a <= b && a <= d && a <= c)
		return (0);
	else if (b <= a && b <= c && b <= d)
		return (2);
	else if (c <= a && c <= b && c <= d)
		return (3);
	else if (d <= b && d <= c && a >= d)
		return (5);
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
	while (tmp)
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
