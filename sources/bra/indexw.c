/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:02:11 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/09 18:02:12 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	check_len(int *acts, t_stack *index, t_stack **lsta, t_int *ind)
{
	int		val_sa;

	swap(lsta, 0, 0);
	val_sa = cycle_through(*lsta, index, index->index, lst_len(*lsta));
	if (val_sa > ind->val)
	{
		(*acts)++;
		ind->val = val_sa;
		if (ind->loud)
			ft_putendl_fd("sa", 1);
		return (1);
	}
	else
	{
		swap(lsta, 0, 0);
		return (0);
	}
}

static void	markup(int index, t_stack *lsta, t_stack *tmp)
{
	int	len;

	len = lst_len(lsta);
	while (len--)
	{
		if (tmp->index == index)
		{
			tmp->move = 0;
			index++;
		}
		else
			(tmp->move) = 1;
		tmp = tmp->next;
		if (!tmp)
			tmp = lsta;
	}
}

static int	moves(t_stack *index, t_stack **lsta, t_stack **lstb, t_int *ind)
{
	int		acts;
	int		len;

	acts = 0;
	len = lst_len(*lsta);
	markup(index->index, *lsta, index);
	while (len--)
	{
		if (check_len(&acts, index, lsta, ind))
			markup(index->index, *lsta, index);
		if ((*lsta)->move)
			push(lsta, lstb, 1, ind->loud);
		else
			rotate(lsta, 0, ind->loud);
		acts++;
	}
	return (acts);
}

static int	ind_deal(t_stack **lsta, t_stack **lstb, t_int *ind)
{
	int		acts;
	int		**arr;
	int		len;

	len = lst_len(*lsta) + lst_len(*lstb);
	acts = 0;
	while (*lstb && lst_len(*lsta) != len)
	{
		arr = ft_calloc(lst_len(*lstb), sizeof(int *) + 1);
		acts += get_act(lsta, lstb, arr, ind);
		free(arr);
	}
	return (acts);
}

int	act_ind(t_stack *lsta, t_stack *lstb, int index, t_int *ind)
{
	int		acts;
	int		*array;
	int		action;
	t_stack	*tmp;

	tmp = lsta;
	while (index--)
		tmp = tmp->next;
	acts = moves(tmp, &lsta, &lstb, ind);
	acts += ind_deal(&lsta, &lstb, ind);
	array = moves_to_a(lsta);
	action = minmax(array[0], array[1], 0);
	acts += action;
	if (action == array[0])
		while (action--)
			rotate(&lsta, 0, ind->loud);
	else
		while (action--)
			r_rotate(&lsta, 0, ind->loud);
	free(array);
	ft_lstclr(&lsta);
	return (acts);
}
