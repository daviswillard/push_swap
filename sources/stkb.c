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

void	rdy_b(t_stack **lsta, t_stack **lstb)
{
	t_stack	*a;
	t_stack	*b;
	int		counter;

	counter = 0;
	a = *lsta;
	b = *lstb;
	if (lst_len(b) == 1 || !lst_len(b))
		return ;
	while (b)
	{
		if (a->index < b->index)
			counter++;
		b = b->next;
	}
	if (counter > lst_len(*lstb) / 2)
		while (counter--)
			r_rotate(lstb, 1);
	else
		while (counter--)
			rotate(lstb, 1);
}

void	gen_case(int first, int last, t_stack **lsta)
{
	int		numb;
	int		temp;

	numb = lst_len(*lsta);
	temp = numb - last + 1;
	if (first > temp)
	{
		while (temp-- > 0)
			r_rotate(lsta, 0);
	}
	else
		while (first-- > 0)
			rotate(lsta, 0);
}

static void	sortb2(t_stack **lst)
{
	int		counter;
	int		max;
	t_stack	*temp;

	temp = *lst;
	max = temp->index;
	counter = 0;
	while (temp)
	{
		if (temp->index > max)
			counter++;
		temp = temp->next;
	}
	if (counter < lst_len(*lst))
		while (counter--)
			r_rotate(lst, 1);
	else
		while (counter--)
			rotate(lst, 1);
}

void	sortb(t_stack **lst)
{
	t_stack	*tmp;
	int		max;

	tmp = *lst;
	max = tmp->index;
	if (lst_len(*lst) == 2 && (*lst)->index < (*lst)->next->index)
	{
		swap(lst, 1);
		return ;
	}
	while (tmp)
	{
		if ((max) < tmp->index)
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return ;
	sortb2(lst);
}
