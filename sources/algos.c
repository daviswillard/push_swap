/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:02:39 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/06 15:35:49 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_all(t_stack *lst)
{
	int	index;

	index = lst->index;
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

void	*algs(int argc, t_stack **lsta, t_stack **lstb)
{
	t_stack	*temp;

	temp = *lsta;
	if (check_all(*lsta))
	{
		ft_putendl_fd("", 1);
		exit(0);
	}
	greed(argc, lsta, lstb);
	return (NULL);
}
