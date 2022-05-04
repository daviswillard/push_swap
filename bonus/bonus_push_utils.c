/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:08:43 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/11 14:31:26 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	swap_bon(t_stack **lst)
{
	t_stack	*temp;

	if (!*lst || lst_len(*lst) < 2)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = (*lst);
	(*lst) = temp;
}

void	push_bon(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!lst_a || !lst_b || !*lst_a)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	if (!*lst_a)
		return ;
	temp = *lst_a;
	*lst_a = (*lst_a)->next;
	temp2 = *lst_b;
	*lst_b = temp;
	(*lst_b)->next = temp2;
}

void	rotate_bon(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!*lst || lst_len(*lst) < 2)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	if (lst_len(*lst) == 2)
		swap_bon(lst);
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
}

void	r_rotate_bon(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!*lst || lst_len(*lst) < 2)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	if (lst_len(*lst) == 2)
		swap_bon(lst);
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
