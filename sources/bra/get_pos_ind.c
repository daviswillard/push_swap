/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_ind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:45:00 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/14 12:50:52 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	cycle_through(t_stack *hold, t_stack *temp, int index, int len)
{
	int	counter;
	int	val;

	val = 0;
	counter = 0;
	while (counter < len)
	{
		if (!temp)
			temp = hold;
		if (index + 1 == temp->index)
		{
			val++;
			index = temp->index;
		}
		temp = temp->next;
		counter++;
	}
	return (val);
}

static int	getting(int len, int **arr, t_stack *hold)
{
	int			val;
	int			index;
	int			max;
	int			cur_pos;
	t_stack		*temp;

	cur_pos = 0;
	max = 0;
	while (cur_pos < len)
	{
		val = 0;
		temp = hold;
		while (val++ < cur_pos)
			temp = temp->next;
		index = temp->index;
		temp = temp->next;
		val = cycle_through(hold, temp, index, len);
		*((*arr) + cur_pos) = val;
		if (!max || val > max)
			max = val;
		cur_pos++;
	}
	return (max);
}

static int	get_index(int val, int *arr, int len)
{
	int	index;

	index = 0;
	while (index < len)
	{
		if (arr[index] == val)
			return (index);
		index++;
	}
	return (-1);
}

int	get_pos_ind(t_stack **lsta, int len, t_int **ind)
{
	int			*arr;
	int			val;

	arr = malloc(sizeof(*arr) * len);
	if (!arr)
		return (-1);
	(*ind)->val = getting(len, &arr, *lsta);
	val = get_index((*ind)->val, arr, len);
	free(arr);
	return (val);
}
