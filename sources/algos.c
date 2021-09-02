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

/*static char	**crt_arr(int argc)
{
	char	**ret;
	int		cntr;

	cntr = 0;
	ret = malloc(sizeof(ret));
	if (!ret)
		exit(-1);
	while (cntr < argc)
	return (ret);
}*/

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
	if (argc >= 100)
		greed(argc, lsta, lstb);
	return (NULL);
}
