/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:51:25 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/09 12:51:27 by dwillard         ###   ########.fr       */
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
	t_int	*grt;
	int		pos[2];
	int		cat[2];
	t_stack	*copy;

	ind = heap_init();
	grt = heap_init();
	pos[0] = get_pos_ind(&lsta, lst_len(lsta), &ind);
	pos[1] = get_pos_grt(&lsta, lst_len(lsta), &grt);
	copy = ft_lstcpy(lsta);
	cat[0] = act_ind(copy, lstb, pos[0], ind);
	return (0);
}
