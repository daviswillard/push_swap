/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:51:32 by dwillard          #+#    #+#             */
/*   Updated: 2021/08/18 18:51:38 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **lst, int out, int loud)
{
	t_stack	*temp;

	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = (*lst);
	(*lst) = temp;
	if (loud)
	{
		if (!out)
			ft_putendl_fd("sa", 1);
		else if (out == 1)
			ft_putendl_fd("sb", 1);
		else if (out == 2)
			ft_putendl_fd("ss", 1);
	}
}

void	push(t_stack **lst_a, t_stack **lst_b, int out, int loud)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!lst_a || !lst_b)
		exit(2);
	if (!*lst_a)
		return ;
	temp = *lst_a;
	*lst_a = (*lst_a)->next;
	temp2 = *lst_b;
	*lst_b = temp;
	(*lst_b)->next = temp2;
	if (loud)
	{
		if (!out)
			ft_putendl_fd("pa", 1);
		else if (out == 1)
			ft_putendl_fd("pb", 1);
	}
}

void	rotate(t_stack **lst, int out, int loud)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (lst_len(*lst) == 2)
		swap(lst, 2, 0);
	else
	{
		temp = *lst;
		*lst = temp->next;
		temp->next = NULL;
		temp2 = (*lst)->next;
		while (temp2->next)
			temp2 = temp2->next;
		temp2->next = temp;
	}
	if (loud)
	{
		if (!out)
			ft_putendl_fd("ra", 1);
		else if (out == 1)
			ft_putendl_fd("rb", 1);
		else if (out == 2)
			ft_putendl_fd("rr", 1);
	}
}

void	r_rotate(t_stack **lst, int out, int loud)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (lst_len(*lst) == 2)
		swap(lst, 2, 0);
	else
	{
		temp2 = *lst;
		while (temp2->next->next)
			temp2 = temp2->next;
		temp = temp2->next;
		temp2->next = NULL;
		temp2 = *lst;
		*lst = temp;
		(*lst)->next = temp2;
	}
	if (loud)
	{
		if (!out)
			ft_putendl_fd("rra", 1);
		else if (out == 1)
			ft_putendl_fd("rrb", 1);
		else if (out == 2)
			ft_putendl_fd("rrr", 1);
	}
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
