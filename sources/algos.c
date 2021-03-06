/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:02:39 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/01 16:59:51 by dwillard         ###   ########.fr       */
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
		exit(0);
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

void	print_stacks(t_stack *lsta, t_stack *lstb)
{
	for (int i = 0; i < lst_len(lsta); i++)
	{
		if (lsta && lst_len(lsta) > i)
		{
			ft_putnbr_fd(lsta->index, STDOUT_FILENO);
			lsta = lsta->next;
		}
		ft_putstr_fd("\t", STDOUT_FILENO);
		if (lstb && lst_len(lstb) > i)
		{
			ft_putnbr_fd(lstb->index, STDOUT_FILENO);
			lstb = lstb->next;
		}
		ft_putendl_fd("", STDOUT_FILENO);
	}
}

void	*algs(t_stack **lsta, t_stack **lstb)
{
	if (check_all(*lsta))
	{
		ft_putstr_fd("", 1);
		exit(0);
	}
	if (lst_len(*lsta) <= 5 && lst_len(*lsta) >= 3)
		sorta(lsta, lstb);
	else if (lst_len(*lsta) == 2)
		swap(lsta, 0, 1);
	else
		bra(*lsta, *lstb);
	print_stacks(*lsta, *lstb);
	return (NULL);
}
