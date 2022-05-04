/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_algos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:07:41 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/11 14:30:08 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void	check_dup(t_stack *lst, int *set)
{
	int		index;
	int		j;

	index = 0;
	while (index < lst_len(lst))
	{
		j = 0;
		while (j < lst_len(lst))
		{
			if (set[j] == set[index])
			{
				if (index != j)
				{
					ft_putendl_fd("Error", 2);
					exit(0);
				}
			}
			j++;
		}
		index++;
	}
}

static int	check_all(t_stack *lst)
{
	int		*set;
	int		index;
	t_stack	*temp;

	temp = lst;
	index = 0;
	set = ft_calloc(lst_len(lst), sizeof(int));
	while (temp)
	{
		set[index++] = temp->integer;
		temp = temp->next;
	}
	check_dup(lst, set);
	free(set);
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

void	*algs(t_stack **lsta, t_stack **lstb)
{
	get_push_swap(lsta, lstb);
	if (check_all(*lsta))
	{
		ft_putendl_fd("OK", 1);
		exit(0);
	}
	else
	{
		ft_putendl_fd("KO", 1);
		exit(0);
	}
}
