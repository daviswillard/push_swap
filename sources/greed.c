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

static void	only_first(int numb, int first, t_stack **lsta)
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
}

static int	action(int first, int last, t_stack **lsta, t_stack **lstb)
{
	int		numb;

	numb = lst_len(*lsta);
	if (first >= 0 && last < 0)
		only_first(numb, first, lsta);
	else if (first >= 0 && last >= 0)
		gen_case(first, last, lsta);
	else
		return (0);
	rdy_b(lsta, lstb);
	push(lsta, lstb, 1);
	sortb(lstb);
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
		if (temp->index < index + 20 && temp->index >= index)
		{
			if (first == -1)
				first = count;
			else
				last = count;
		}
		temp = temp->next;
		count++;
	}
	return (action(first, last, lsta, lstb));
}

int	greed(int argc, t_stack **lsta, t_stack **lstb)
{
	int	index;
	int	key;

	index = 0;
	while (index < argc)
	{
		while (lst_len(*lsta) > 5 && index < argc)
		{
			key = finder(index, lsta, lstb);
			if (!key)
				break ;
		}
		index += 20;
		if (lst_len(*lsta) <= 5)
		{
			sorta(lsta, lstb, argc);
			break ;
		}
	}
	return (0);
}
