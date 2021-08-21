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

void	swap(t_stack **lst)
{
	t_stack	*temp;

	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = (*lst);
	(*lst) = temp;
}

void	push(t_stack **lst_a, t_stack **lst_b)
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
}

void	rotate(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *lst;
	*lst = temp->next;
	temp->next = NULL;
	temp2 = (*lst)->next;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp;
}

void	r_rotate(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp2 = *lst;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp = temp2->next;
	temp2->next = NULL;
	temp2 = *lst;
	*lst = temp;
	(*lst)->next = temp2;
}
