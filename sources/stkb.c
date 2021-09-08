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

static void	extrdy_b(t_stack **lsta, t_stack **lstb)
{
	t_stack	*temp;
	int		counter1;
	int		counter2;

	counter1 = 0;
	counter2 = 0;
	temp = *lstb;
	while (temp)
	{
		if (temp->index > (*lsta)->index)
			counter1++;
		if (temp->index < (*lsta)->index)
			counter2++;
		temp = temp->next;
	}
	if (counter1 > counter2)
		while (counter1--)
			rotate(lstb, 1);
	else
		while (counter2--)
			rotate(lstb, 0);
}

int	rdy_b(t_stack **lsta, t_stack **lstb)
{
	int		ind;
	int		counter;
	int		state;
	t_stack	*temp;

	state = 0;
	counter = 0;
	temp = *lstb;
	ind = (*lsta)->index;
	if (!temp)
		return (0);
	while (temp && ++counter)
	{
		if ((!state || state == 2) && temp->index > ind)
			state++;
		if ((!state || state == 1) && temp->index < ind)
			state += 2;
		temp = temp->next;
	}
	if (state == 3)
		extrdy_b(lsta, lstb);
	return (state);
}

void	gen_case(int first, int last, t_stack **lsta, t_stack **lstb)
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

void	sortb(t_stack **lst, int state)
{
	int		counter;
	t_stack	*temp;

	counter = 0;
	temp = *lst;
	while (temp)
	{
		if (!counter)
			printf("stack b1:\n");
		printf("%-5d\n", temp->index);
		counter++;
		temp = temp->next;
	}
	counter = 0;
	temp = *lst;
	if (!lst_len(*lst) || lst_len(*lst) == 1 || !state || state == 1)
		return ;
	if (state == 2)
		rotate(lst, 1);
	if (state == 3)
	{
		while (temp)
		{
			if (temp->index > (*lst)->index)
				counter++;
			temp = temp->next;
		}
		while (counter--)
			r_rotate(lst, 1);
	}
	counter = 0;
	temp = *lst;
	while (temp)
	{
		if (!counter)
			printf("stack b2:\n");
		printf("%-5d\n", temp->index);
		counter++;
		temp = temp->next;
	}
}
