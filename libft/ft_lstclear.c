/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:57:54 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/27 15:57:56 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst, void (*del)(int))
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *lst;
	while (temp)
	{
		del(temp->integer);
		del(temp->index);
		temp2 = temp;
		temp = temp2->next;
		free(temp2);
	}
	*lst = NULL;
}
