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

static t_stack	*move(int pos, t_stack *temp)
{
	int	mv;

	mv = 0;
	while (mv++ < pos)
	{
		temp = temp->next;
		if (temp == NULL)
		{
			printf("Ошибка в t_stack *move");
			exit (-1);
		}
	}
	return (temp);
}

static void	only_first(int numb, int first, t_stack **lsta, t_stack **lstb)
{
	t_stack	*temp;
	int		counter;

	counter = 0;
	temp = move(first, *lsta);
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
	if (first == -1 && last == -1)
		return (0);
	return (action(first, last, lsta, lstb));
}

int	greed(int argc, t_stack **lsta, t_stack **lstb)
{
	int	index;
	int	key;

	index = 0;
	while (index < argc)
	{
		key = finder(index, lsta, lstb);
		while (key)
			key = finder(index, lsta, lstb);
		index += 20;
	}
}
