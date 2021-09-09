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

static int	decide(int pos0, int pos1)
{
	int decision;

	if (pos0 > pos1)
		decision = 0;
	else
		decision = 1;
	return (decision);
}

int	bra(int argc, t_stack *lsta, t_stack *lstb)
{
	(void)argc;
	(void)lstb;
	int	pos[2];
	int	cat[2];

	pos[0] = get_pos_ind(&lsta, lst_len(lsta));
	pos[1] = get_pos_grt(&lsta, lst_len(lsta));
	cat[0] = act_ind(argc, lsta, lstb, pos[0]);
	return (0);
}
