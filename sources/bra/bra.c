/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:51:25 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/30 12:51:43 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_int	*heap_init(void)
{
	t_int	*ret;

	ret = malloc(sizeof(t_int));
	if (!ret)
		return (NULL);
	ret->loud = 1;
	return (ret);
}

int	bra(t_stack *lsta, t_stack *lstb)
{
	t_int	*ind;
	int		pos;
	int		cat;
	t_stack	*copy;

	ind = heap_init();
	pos = get_pos_ind(&lsta, lst_len(lsta), &ind);
	copy = ft_lstcpy(lsta);
	cat = act_ind(copy, lstb, pos, ind);
	free(ind);
	return (cat);
}
