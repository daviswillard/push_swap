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
	t_stack	*chk;

	chk = *lsta;
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
