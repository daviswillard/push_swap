/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:00:22 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/03 18:38:16 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

t_stack	*ft_lstcpy(t_stack *base)
{
	t_stack	*copy;
	t_stack	*temp;
	t_stack	*temp2;

	temp = base->next;
	copy = ft_lstnew(base->integer, base->index);
	if (!copy)
		return (NULL);
	temp2 = copy;
	while (temp)
	{
		temp2->next = ft_lstnew(temp->integer, temp->index);
		if (!temp2->next)
			return (NULL);
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
	algs(argc - 1, &stka, &stkb);
	return (0);
}
