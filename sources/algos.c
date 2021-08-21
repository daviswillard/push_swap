/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:02:39 by dwillard          #+#    #+#             */
/*   Updated: 2021/08/21 17:02:40 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_all(t_stack *lst)
{
	int	index;

	index = 0;
	while (lst)
	{
		if (index == lst->index)
			index++;
		else
			return (0);
		lst = lst->next;
	}
	return (1);
}

char	**algs(t_stack **lst)
{
	char	**arr;



	return (arr);
}