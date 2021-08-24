/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:50:06 by dwillard          #+#    #+#             */
/*   Updated: 2021/08/24 17:50:11 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	finder(int cntr, int grp, int denom, t_stack **lsta, t_stack **lstb)
{
	int		ind_first;
	int		ind_last;
	t_stack	temp;

	temp = **lsta;
	while (cntr < denom + 1)
	{
		while (temp.index >= grp * cntr && temp.index < grp * (cntr - 1))
			temp = *temp.next;
		ind_first = temp.index;
		while (temp.next)
		{
			if (temp.index < grp * cntr && temp.index >= grp * (cntr - 1))
				ind_last = temp.index;
			temp = *temp.next;
		}
	}
}

char	*greed(int argc, t_stack **lsta, t_stack **lstb)
{
	int		denom;
	int		grp;
	int		cntr;

	denom = 5;
	grp = 20;
	cntr = 1;
}
