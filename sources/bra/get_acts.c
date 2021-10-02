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

/*
 * mv[0] - ra;
 * mv[1] - rra;
 * mv[2] - rb;
 * mv[3] - rrb;
 * arr[0] - rr + ra/rb;
 * arr[1] - ra + rrb;
 * arr[2] - rrr + rra/rrb;
 * arr[3] - rra + rb;
 */
static int	ind_modes(int *mv, int min_mode, int value)
{
	if (!value)
	{
		if (!min_mode || min_mode == 1)
			return (minmax(mv[0], mv[2], 0));
		else if (min_mode == 2)
			return (mv[0]);
		else if (min_mode == 3 || min_mode == 4)
			return (minmax(mv[1], mv[3], 0));
		else
			return (mv[1]);
	}
	else
	{
		if (!min_mode || min_mode == 1)
			return (minmax(mv[0], mv[2], 1) - minmax(mv[0], mv[2], 0));
		else if (min_mode == 2)
			return (mv[3]);
		else if (min_mode == 3 || min_mode == 4)
			return (minmax(mv[1], mv[3], 1) - minmax(mv[1], mv[3], 0));
		else
			return (mv[2]);
	}
}
/*
 * minmax - функция, которая считает либо максимальное, либо минимальное
 * значение из двух, в зависимости от того, что мы передаем третьим аргументом
 */

static int	*decide_action(int *mv)
{
	int		arr[4];
	int		*values;

	arr[0] = minmax(mv[0], mv[2], 1);
	arr[1] = mv[0] + mv[3];
	arr[2] = minmax(mv[1], mv[3], 1);
	arr[3] = mv[1] + mv[2];
	values = ft_calloc(4, sizeof(int));
	values[0] = min_val(arr[0], arr[1], arr[2], arr[3]);
	values[1] = min_mode(arr[0], arr[1], arr[2], arr[3]);
	if (!values[1] && mv[2] > mv[0])
		values[1] = 1;
	else if (values[1] == 3 && mv[3] > mv[1])
		values[1] = 4;
	values[2] = ind_modes(mv, values[1], 0);
	values[3] = ind_modes(mv, values[1], 1);
	free(mv);
	return (values);
}
/*
 * values[0] количество действий для получения необходимого лайнапа
 * values[1] действия, которые будут выполняться для сортировки
 * values[2 - 3] количество необходимых действий
 * modes:
 * 0:	rr & ra
 * 1:	rr & rb
 * 2:	ra & rrb
 * 3:	rrr & rra
 * 4:	rrr & rrb
 * 5:	rb & rra
 */

static int	*marker(t_stack **lsta, t_stack **lstb, int mark, int index)
{
	int		*t_index;
	int		*mv;
	t_stack	*temp;

	temp = *lstb;
	while (index)
	{
		temp = temp->next;
		index--;
	}
	if (mark)
		mv = moves_to_a(*lsta);
	else
		mv = moves_to_a_2(*lsta, temp->index);
	mv = moves_to_b(*lstb, temp->index, mv);
	t_index = decide_action(mv);
	return (t_index);
}

int	get_act(t_stack **lsta, t_stack **lstb, int **arr, t_int *ind)
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
		if (temp->index < edg.low || temp->index > edg.high)
			arr[index] = marker(lsta, lstb, -1, index);
		else
			arr[index] = marker(lsta, lstb, 0, index);
		if (arr[index][0] <= 2)
			break ;
		index++;
		temp = temp->next;
	}
	if (index == lst_len(*lstb))
		index = elem_index(arr, lst_len(*lstb));
	acts = arr[index][0];
	do_the_action(lsta, lstb, arr[index], ind);
	index = 0;
	while (index < lst_len(*lstb))
		free(arr[index++]);
	push(lstb, lsta, 0, ind->loud);
	return (acts);
}
