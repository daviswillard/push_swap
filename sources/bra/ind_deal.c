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

/*mem is allocated in this function: be careful!*/

//пара функций, которые должны посчитать кол-во ходов для сортировки стэка а

static int	*moves_to_a_2(t_stack *lsta, int index)
{
	int		*moves;
	int		len;
	t_stack	*temp;
	t_stack	*temp2;

	len = lst_len(lsta);
	temp = ft_lstcpy(lsta);
	temp2 = ft_lstcpy(lsta);
	moves = ft_calloc(2, 4);
	if (temp->index < index)
		while (temp->index < index && moves[0]++ > -1)
			rotate(&temp, 0, 0);
	else
	{
		while (temp->index > index && moves[0]++ > -1)
			rotate(&temp, 0, 0);
		while (temp->index < index && moves[0]++ > -1)
			rotate(&temp, 0, 0);
	}
	ft_lstclr(&temp);
	ft_lstclr(&temp2);
	return (moves);
}

static int	*moves_to_a(t_stack *lsta)
{
	int		min;
	int		*moves;
	t_stack	*temp;
	t_stack	*temp2;

	min = lst_len(lsta + 1);
	temp = ft_lstcpy(lsta);
	moves = ft_calloc(2, 4);
	temp2 = temp;
	while (temp2)
	{
		if (min > temp2->index)
			min = temp2->index;
		temp2 = temp2->next;
	}
	temp2 = ft_lstcpy(lsta);
	while (temp->index != min && moves[0]++ > -1)
		r_rotate(&temp, 1, 0);
	while (temp->index != min && moves[1]++ > -1)
		rotate(&temp, 0, 0);
	ft_lstclr(&temp);
	ft_lstclr(&temp2);
	return (moves);
}

static int	marker(t_stack **lsta, t_stack **lstb, int mark, int index)
{
	t_stack	*temp;
	int		t_index;

	t_index = index;
	temp = *lstb;
	while (t_index--)
		temp = temp->next;
	if (mark)
		moves_to_a(*lsta);
	else
		moves_to_a_2(*lsta, temp->index);
	return (0);
}

static int	get_act(t_stack **lsta, t_stack **lstb, int *arr, t_int *ind)
{
	int		acts;
	int		index;
	t_lowhi	edg;
	t_stack	*temp;

	temp = *lstb;
	edg = hilow(lsta);
	index = 0;
	while (temp)
	{
		if (temp->index < edg.low)
			arr[index] = marker(lsta, lstb, -1, index);
		else if (temp->index > edg.high)
			arr[index] = marker(lsta, lstb, 1, index);
		else
			arr[index] = marker(lsta, lstb, 0, index);
		index++;
		temp = temp->next;
	}
	return (acts);
}

int	ind_deal(t_stack **lsta, t_stack **lstb, t_int *ind)
{
	int		acts;
	int		*arr;

	arr = malloc(sizeof(int) * lst_len(*lstb));
	while (*lstb)
		acts += get_act(lsta, lstb, arr, ind);
	free(arr);
	return (acts);
}
