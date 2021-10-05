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

static t_int	*heap_init(int flag)
{
	t_int	*ret;

	ret = malloc(sizeof(t_int));
	if (!ret)
		return (NULL);
	ret->loud = 0;
	ret->ig = flag;
	return (ret);
}

static int	decide(int a, int b, t_int *ind, t_int *grt)
{
	if (a < b)
	{
		ind->loud = 1;
		return (0);
	}
	else
		grt->loud = 1;
	return (1);
}

int	bra(t_stack *lsta, t_stack *lstb)
{
	t_int	*ind;
	t_int	*grt;
	int		pos[2];
	int		cat[2];
	t_stack	*copy;

	ind = heap_init(0);
	grt = heap_init(1);
	pos[0] = get_pos_ind(&lsta, lst_len(lsta), &ind);
	pos[1] = get_pos_grt(&lsta, lst_len(lsta), &grt);
	copy = ft_lstcpy(lsta);
	cat[0] = act_ind(copy, lstb, pos[0], ind);
	copy = ft_lstcpy(lsta);
	cat[1] = act_ind(copy, lstb, pos[1], grt);
	copy = ft_lstcpy(lsta);
	if (!decide(cat[0], cat[1], ind, grt))
		act_ind(copy, lstb, pos[0], ind);
	else
		act_ind(copy, lstb, pos[1], grt);
	free(ind);
	free(grt);
	return (0);
}