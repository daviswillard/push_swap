/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:50:06 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/06 16:39:14 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	only_first(int numb, int first, t_stack **lsta, t_stack **lstb)
{
	if (first > numb / 2)
	{
		while (numb - (first++) + 1 > 0)
			r_rotate(lsta, 0);
	}
	else
	{
		while (first-- > 0)
			rotate(lsta, 0);
	}
	rdy_b(lstb, lsta);
}

static int	action(int first, int last, t_stack **lsta, t_stack **lstb)
{
	int		numb;
	t_stack	*temp;

	temp = *lsta;
	numb = 0;
	while (temp)
	{
		numb++;
		temp = temp->next;
	}
	if (first >= 0 && last < 0)
		only_first(numb, first, lsta, lstb);
	else if (first >= 0 && last >= 0)
		gen_case(first, last, lsta, lstb);
	else
		return (0);
	push(lsta, lstb, 1);
	return (1);
}

static int	finder(int index, t_stack **lsta, t_stack **lstb)
{
	int		first;
	int		last;
	int		count;
	t_stack	*temp;

	first = -1;
	last = -1;
	count = 0;
	temp = *lsta;
	while (temp)
	{
		if (temp->index < index + 5 && temp->index >= index)
		{
			if (first == -1)
				first = count;
			else
				last = count;
		}
		temp = temp->next;
		count++;
	}
	if (first == -1 && last == -1)
		return (0);
	return (action(first, last, lsta, lstb));
}

int	lst_len(t_stack *lst)
{
	int		ret_counter;

	ret_counter = 0;
	while (lst)
	{
		ret_counter++;
		lst = lst->next;
	}
	return (ret_counter);
}

int	greed(int argc, t_stack **lsta, t_stack **lstb)
{
	int	index;
	int	key;

	index = 0;
	while (index < argc)
	{
		key = finder(index, lsta, lstb);
		while (key && lst_len(*lsta) > 5)
			key = finder(index, lsta, lstb);
		if (lst_len(*lsta) <= 5)
		index += 5;
	}
	return (0);
}
