/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:21:27 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/27 12:21:30 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(int integer, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack *));
	if (!new)
		return (NULL);
	if (integer)
		new->integer = integer;
	else
	{
		ft_printf("Error\n");
		exit(1);
	}
	new->index = index;
	new->next = NULL;
	return (new);
}
