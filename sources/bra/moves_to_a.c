/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:16:13 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/21 13:16:15 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
 * пара функций, считающих шаги для сортировки стэка а при использовании
 * rotate и r_rotate соответственно
 */
static void	rotater(t_stack *lst, int before, int *mv)
{
	int		after;
	t_stack	*temp;

	temp = lst;
	while (temp->index != before && temp->next)
		temp = temp->next;
	if (!temp->next)
		temp = lst;
	else
		temp = temp->next;
	after = temp->index;
	temp = lst;
	while (temp->index != after)
	{
		(*mv)++;
		temp = temp->next;
	}
}

/*
 * пара функций, которые должны посчитать кол-во ходов для сортировки стэка а
 */

int	*moves_to_a_2(t_stack *lsta, int index)
{
	int		*moves;
	int		before;
	t_stack	*temp;

	temp = lsta;
	before = -1;
	while (temp)
	{
		if (temp->index < index && before < temp->index)
			before = temp->index;
		temp = temp->next;
	}
	if (before > 0)
	{
		moves = ft_calloc(4, sizeof(int));
		rotater(lsta, before, &moves[0]);
		moves[1] = lst_len(lsta) - moves[0];
	}
	else
		moves = moves_to_a(lsta);
	return (moves);
}

int	*moves_to_a(t_stack *lsta)
{
	int		min;
	int		*moves;
	t_stack	*temp;

	min = 0x7fffffff;
	moves = ft_calloc(4, 4);
	temp = lsta;
	while (temp)
	{
		if (min > temp->index)
			min = temp->index;
		temp = temp->next;
	}
	temp = lsta;
	while (temp->index != min && moves[0]++ > -1)
		temp = temp->next;
	moves[1] = lst_len(lsta) - moves[0];
	return (moves);
}
/*
 * здесь mv[0] и mv[1] это количество ra и rra, а
 * mv[2] и mv[3] rb и rrb соответственно
 */

int	*moves_to_b(t_stack *lstb, int index, int *moves)
{
	t_stack	*temp;

	temp = lstb;
	while (temp->index != index && moves[2]++ > -1)
		temp = temp->next;
	if (lst_len(lstb) > 1)
		moves[3] = lst_len(lstb) - moves[2];
	return (moves);
}
