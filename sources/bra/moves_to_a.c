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
static int	rotater(t_stack *lst, int before)
{
	int		ret;
	int		after;
	t_stack	*temp;

	temp = lst;
	while (temp->index != before)
		temp = temp->next;
	if (!temp->next)
		temp = lst;
	else
		temp = temp->next;
	after = temp->index;
	ret = 0;
	while (lst->index != after)
	{
		ret++;
		rotate(&lst, 0, 0);
	}
	return (ret);
}

static int	r_rotater(t_stack *lst, int before)
{
	int		ret;
	int		after;
	t_stack	*temp;

	temp = lst;
	while (temp->index != before)
		temp = temp->next;
	if (!temp->next)
		temp = lst;
	else
		temp = temp->next;
	after = temp->index;
	ret = 0;
	while (lst->index != after)
	{
		ret++;
		r_rotate(&lst, 0, 0);
	}
	return (ret);
}

/*mem is allocated in this function: be careful!*/

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
	moves = ft_calloc(4, 4);
	moves[0] = rotater(temp, before);
	moves[1] = r_rotater(temp2, before);
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
 * здесь mv[0] и mv[1] это количество ra и rra соответственно
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
