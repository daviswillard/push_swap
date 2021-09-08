/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:43:28 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/07 14:43:29 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	casef(t_stack **lsta, t_stack *tmp)
{
	if (tmp->index < tmp->next->index && tmp->index < (*lsta)->index)
		swap(lsta, 0);
	else if (tmp->index > tmp->next->index && tmp->index > (*lsta)->index)
		r_rotate(lsta, 0);
	else if (tmp->index < tmp->next->index && tmp->index < (*lsta)->index)
		rotate(lsta, 0);
	else
	{
		swap(lsta, 0);
		r_rotate(lsta, 0);
	}
}

static void	rdy_a(t_stack **lsta, t_stack **lstb, int counter)
{
	int	len;
	int	hold;

	len = lst_len(*lsta);
	hold = counter;
	if (counter > len / 2)
	{
		while (len - counter++ + 1)
			r_rotate(lsta, 0);
		push(lstb, lsta, 0);
		while (counter-- != hold - 1)
			rotate(lsta, 0);
	}
	else
	{
		while (counter--)
			rotate(lsta, 0);
		push(lstb, lsta, 0);
		while (counter++ != hold)
			r_rotate(lsta, 0);
	}
}

static void	get_b_back(t_stack **lsta, t_stack **lstb)
{
	t_stack		*temp;
	int			counter;

	temp = *lsta;
	counter = 0;
	while (temp->next)
		temp = temp->next;
	if ((*lstb)->index < (*lsta)->index)
		push(lstb, lsta, 1);
	else if (temp->index > (*lstb)->index)
	{
		push(lstb, lsta, 1);
		r_rotate(lsta, 0);
	}
	else
	{
		while (temp->index < (*lstb)->index && ++counter < lst_len(*lsta)
			&& temp->next)
			temp = temp->next;
		rdy_a(lsta, lstb, counter);
	}
}

void	sorta(t_stack **lsta, t_stack **lstb)
{
	t_stack		*tmp;

	if (lst_len(*lsta) > 3)
		while (lst_len(*lsta) != 3)
			push(lsta, lstb, 1);
	tmp = (*lsta)->next;
	if (tmp->index < (*lsta)->index)
		casef(lsta, tmp);
	else
	{
		if (tmp->index < tmp->next->index)
			return ;
		else
		{
			swap(lsta, 0);
			rotate(lsta, 0);
		}
	}
	while (lst_len(*lsta) < 5)
		get_b_back(lsta, lstb);
}
