/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:54:19 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/03 18:44:37 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	extrdy_b(t_stack **lstb, t_stack **lsta, int state)
{
	t_stack	*temp;
	int		counter1;
	int		counter2;

	counter1 = 0;
	counter2 = 0;
	temp = *lstb;
	if (!state || state == 1 || state == 2)
		return ;
	else
	{
		while (temp)
		{
			if (temp->index > (*lsta)->index)
				counter1++;
			if (temp->index < (*lsta)->index)
				counter2++;
		}
		if (counter1 > counter2)
			while (counter1--)
				rotate(lstb, 1);
		else
			while (counter2--)
				rotate(lstb, 0);
	}
}

static void	rdy_b(t_stack **lstb, t_stack **lsta)
{
	int		indtmp;
	int		counter;
	int		state;
	t_stack	*temp;

	state = 0;
	counter = 0;
	temp = *lstb;
	indtmp = (*lsta)->index;
	if (!*lstb)
		return ;
	while (temp && ++counter)
	{
		if ((!state || state == 2) && temp->index > indtmp)
			state++;
		if ((!state || state == 1) && temp->index < indtmp)
			state += 2;
		temp = temp->next;
	}
	extrdy_b(lstb, lsta, state);
}

void	gen_case(int first, int last, t_stack **lsta, t_stack **lstb)
{
	int		numb;
	int		tempi;
	t_stack	*temp;

	temp = *lsta;
	numb = 0;
	while (temp)
	{
		numb++;
		temp = temp->next;
	}
	tempi = numb - last + 1;
	if (first > tempi)
	{
		while (tempi-- > 0)
			rotate(lsta, 0);
	}
	else
		only_first(numb, first, lsta);
	rdy_b(lstb, lsta);
	push(lsta, lstb, 1);
}
