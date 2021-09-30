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

#include "../../push_swap.h"

static void	casef(t_stack **lsta, t_stack *tmp)
{
	if (tmp->index < tmp->next->index && tmp->next->index < (*lsta)->index)
		rotate(lsta, 0, 1);
	else if (tmp->index > tmp->next->index)
	{
		swap(lsta, 0, 1);
		r_rotate(lsta, 0, 1);
	}
	else if ((*lsta)->index < tmp->next->index)
		swap(lsta, 0, 1);
}

static void	rdy_a(t_stack **lsta, t_stack **lstb, int counter)
{
	int	len;
	int	hold;

	len = lst_len(*lsta);
	hold = counter;
	if (counter <= len / 2)
	{
		while (counter-- > 0)
			r_rotate(lsta, 0, 1);
		push(lstb, lsta, 0, 1);
		while (counter++ < hold)
			rotate(lsta, 0, 1);
	}
	else
	{
		while (len - counter++ > 0)
			rotate(lsta, 0, 1);
		push(lstb, lsta, 0, 1);
		while (counter++ < hold)
			r_rotate(lsta, 0, 1);
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
		push(lstb, lsta, 0, 1);
	else if (temp->index < (*lstb)->index)
	{
		push(lstb, lsta, 0, 1);
		rotate(lsta, 0, 1);
	}
	else
	{
		temp = (*lsta);
		while (temp)
		{
			if (temp->index > (*lstb)->index)
				counter++;
			temp = temp->next;
		}
		rdy_a(lsta, lstb, counter);
	}
}

static void	small_sort(t_stack **lsta)
{
	t_stack	*temp;
	int		counter;
	int		min;

	min = 0;
	counter = 0;
	temp = *lsta;
	while (temp)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	temp = (*lsta);
	while (temp->index != min && counter++ < lst_len(*lsta))
		temp = temp->next;
	if (counter < lst_len(*lsta) / 2)
		while ((*lsta)->index != min)
			rotate(lsta, 0, 1);
	else
		while ((*lsta)->index != min)
			r_rotate(lsta, 0, 1);
}

void	sorta(t_stack **lsta, t_stack **lstb)
{
	t_stack		*tmp;
	t_stack		*temp;

	if (lst_len(*lsta) > 3)
		while (lst_len(*lsta) != 3)
			push(lsta, lstb, 1, 1);
	tmp = (*lsta)->next;
	temp = tmp->next;
	if (tmp->index < (*lsta)->index)
		casef(lsta, tmp);
	else
	{
		if (tmp->index < temp->index)
			;
		else if (tmp->index > temp->index && (*lsta)->index > temp->index)
			r_rotate(lsta, 0, 1);
		else
		{
			swap(lsta, 0, 1);
			rotate(lsta, 0, 1);
		}
	}
	while (*lstb)
		get_b_back(lsta, lstb);
	small_sort(lsta);
}
