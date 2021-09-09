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

int	bra(int argc, t_stack *lsta, t_stack *lstb)
{
	(void)argc;
	(void)lstb;
	int	pos[2];

	pos[0] = get_pos_ind(&lsta, lst_len(lsta));
	pos[1] = get_pos_grt(&lsta, lst_len(lsta));
	return (0);
}
