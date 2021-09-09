/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_grt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:47:26 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/09 16:47:31 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	cycle_through(t_stack *hold, t_stack *temp, int integer, int len)
{
	int	counter;
	int	val;

	val = 0;
	counter = 0;
	while (counter < len)
	{
		if (!temp)
			temp = hold;
		if (integer < temp->integer)
		{
			val++;
			integer = temp->integer;
		}
		temp = temp->next;
		counter++;
	}
	return (val);
}

static int	getting(int len, int **arr, t_stack *hold)
{
	int			val;
	int			integer;
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
		integer = temp->integer;
		temp = temp->next;
		val = cycle_through(hold, temp, integer, len);
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

int		get_pos_grt(t_stack **lsta, int len)
{
	t_stack		*hold;
	int			*arr;
	int			val;

	hold = *lsta;
	arr = malloc(sizeof(*arr) * len);
	if (!arr)
		return (-1);
	val = getting(len, &arr, hold);
	val = get_index(val, arr, len);
	free(arr);
	return (val);
}
