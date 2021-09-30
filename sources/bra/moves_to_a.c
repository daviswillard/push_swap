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
static void	rotater(t_stack **lst, int before, int *mv)
{
	int		after;
	t_stack	*temp;

	temp = *lst;
	while (temp->index != before)
		temp = temp->next;
	if (!temp->next)
		temp = *lst;
	else
		temp = temp->next;
	after = temp->index;
	while ((*lst)->index != after)
	{
		(*mv)++;
		rotate(lst, 0, 0);
	}
}

static void	r_rotater(t_stack **lst, int before, int *mv)
{
	int		after;
	t_stack	*temp;

	temp = *lst;
	while (temp->index != before)
		temp = temp->next;
	if (!temp->next)
		temp = *lst;
	else
		temp = temp->next;
	after = temp->index;
	while ((*lst)->index != after)
	{
		(*mv)++;
		r_rotate(lst, 0, 0);
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
	t_stack	*temp2;

	temp = lsta;
	before = -1;
	while (temp)
	{
		if (temp->index < index && before < temp->index)
			before = temp->index;
		temp = temp->next;
	}
	temp = ft_lstcpy(lsta);
	temp2 = ft_lstcpy(lsta);
	moves = ft_calloc(4, sizeof(int));
	rotater(&temp, before, &moves[0]);
	r_rotater(&temp2, before, &moves[1]);
	ft_lstclr(&temp);
	ft_lstclr(&temp2);
	return (moves);
}

int	*moves_to_a(t_stack *lsta)
{
	int		min;
	int		*moves;
	t_stack	*temp;
	t_stack	*temp2;

	min = 0x7fffffff;
	temp = ft_lstcpy(lsta);
	moves = ft_calloc(4, 4);
	temp2 = temp;
	while (temp2)
	{
		if (min > temp2->index)
			min = temp2->index;
		temp2 = temp2->next;
	}
	temp2 = ft_lstcpy(lsta);
	while (temp->index != min && moves[0]++ > -1)
		rotate(&temp, 1, 0);
	while (temp2->index != min && moves[1]++ > -1)
		r_rotate(&temp2, 0, 0);
	ft_lstclr(&temp);
	ft_lstclr(&temp2);
	return (moves);
}
/*
 * здесь mv[0] и mv[1] это количество ra и rra, а
 * mv[2] и mv[3] rb и rrb соответственно
 */

int	*moves_to_b(t_stack *lstb, int index, int *moves)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = ft_lstcpy(lstb);
	temp2 = ft_lstcpy(lstb);
	while (temp->index != index && moves[2]++ > -1)
		rotate(&temp, 1, 0);
	while (temp2->index != index && moves[3]++ > -1)
		r_rotate(&temp2, 1, 0);
	ft_lstclr(&temp);
	ft_lstclr(&temp2);
	return (moves);
}
