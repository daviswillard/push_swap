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

static void	check_len(int *acts, t_stack **lsta, int len, t_int *ind)
{
	int		val;
	int		val_sa;

	val = cycle_through(*lsta, *lsta, (*lsta)->index, len);
	swap(lsta, 0, 0);
	val_sa = cycle_through(*lsta, *lsta, (*lsta)->index, len);
	if (val_sa > val)
	{
		(*acts)++;
		if (ind->loud)
			ft_putendl_fd("sa", 1);
	}
	else
		swap(lsta, 0, 0);
}

int	act_ind(t_stack *lsta, t_stack *lstb, int index, t_int *ind)
{
	int		len;
	int		acts;
	t_stack	*tmp;

	acts = 0;
	tmp = lsta;
	len = lst_len(lsta);
	while (index--)
		tmp = tmp->next;
	index = tmp->index;
	while (len--)
	{
		if (index + 1 == tmp->index)
		{
			acts++;
			index++;
			push(&lsta, &lstb, 1, ind->loud);
		}
		if (!tmp->next)
			tmp = lsta;
		tmp = tmp->next;
		check_len(&acts, &lsta, len, ind);
	}
	return (acts);
}
