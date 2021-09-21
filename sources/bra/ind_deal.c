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
 */
static int	decide_action(t_stack *lsta, t_stack *lstb, int *mv)
{
	int		arr[4];

	arr[0] = max(mv[0], mv[2]);
	arr[1] = mv[0] + mv[3];
	arr[2] = max(mv[1], mv[3]);
	arr[3] = mv[1] + mv[2];
	free(mv);
	return (min(arr[0], arr[1], arr[2], arr[3]));
}

static int	*moves_to_b(t_stack *lstb, int index, int *moves)
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

static int	marker(t_stack **lsta, t_stack **lstb, int mark, int index)
{
	int		t_index;
	int		*mv;
	t_stack	*temp;

	t_index = index;
	temp = *lstb;
	while (t_index)
	{
		temp = temp->next;
		t_index--;
	}
	if (mark)
		mv = moves_to_a(*lsta);
	else
		mv = moves_to_a_2(*lsta, temp->index);
	mv = moves_to_b(*lstb, temp->index, mv);
	t_index = decide_action(*lsta, *lstb, mv);
	return (t_index);
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
		if (temp->index < edg.low || temp->index > edg.high)
			arr[index] = marker(lsta, lstb, -1, index);
		else
			arr[index] = marker(lsta, lstb, 0, index);
		index++;
		temp = temp->next;
	}
	while (index > -1)
	{
		printf("index = %d\nvalue = %d\n\n", index, arr[index]);
		index--;
	}
	return (acts);
}

int	ind_deal(t_stack **lsta, t_stack **lstb, t_int *ind)
{
	int		acts;
	int		*arr;

	arr = ft_calloc(lst_len(*lstb), sizeof(int));
	acts = 0;
//	while (*lstb)
		acts += get_act(lsta, lstb, arr, ind);
	free(arr);
	return (acts);
}
