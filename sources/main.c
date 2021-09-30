/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:00:22 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/30 13:00:17 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclr(t_stack **list)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *list;
	while (temp)
	{
		temp->index = 0;
		temp->integer = 0;
		temp->move = 0;
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	*list = NULL;
}

t_stack	*ft_lstcpy(t_stack *base)
{
	t_stack	*copy;
	t_stack	*temp;
	t_stack	*temp2;

	temp = base->next;
	copy = ft_lstnew(base->integer, base->index);
	if (!copy)
		exit(1);
	temp2 = copy;
	while (temp)
	{
		temp2->next = ft_lstnew(temp->integer, temp->index);
		if (!temp2->next)
			exit(1);
		temp = temp->next;
		temp2 = temp2->next;
	}
	return (copy);
}

int	main(int argc, char **argv)
{
	t_stack	*stka;
	t_stack	*stkb;

	stkb = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	stka = get_args(argc, argv);
	algs(&stka, &stkb);
	return (0);
}
