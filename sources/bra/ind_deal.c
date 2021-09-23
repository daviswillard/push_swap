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
 * arr[3] - rra + ra;
 */
static int	*decide_action(t_stack *lsta, t_stack *lstb, int *mv)
{
	int		arr[4];
	int		*values;

	arr[0] = max(mv[0], mv[2]);
	arr[1] = mv[0] + mv[3];
	arr[2] = max(mv[1], mv[3]);
	arr[3] = mv[1] + mv[2];
	values = ft_calloc(4, sizeof(int));
	*values = min_val(arr[0], arr[1], arr[2], arr[3]);
	*(values + 1) = min_mode(arr[0], arr[1], arr[2], arr[3]);
	*(values + 2) = ;
	*(values + 3) = ;
	free(mv);
	return (values);
}

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
	t_index = decide_action(*lsta, *lstb, mv);
	return (t_index);
}

static int	get_act(t_stack **lsta, t_stack **lstb, int **arr, t_int *ind)
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
	return (acts);
}

int	ind_deal(t_stack **lsta, t_stack **lstb, t_int *ind)
{
	int		acts;
	int		**arr;

	arr = ft_calloc(lst_len(*lstb), sizeof(int *) + 1);
	acts = 0;
//	while (*lstb)
		acts += get_act(lsta, lstb, arr, ind);
	free(arr);
	return (acts);
}
