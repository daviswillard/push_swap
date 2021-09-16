/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:02:11 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/09 18:02:12 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	check_len(int *acts, t_stack *index, t_stack **lsta, t_int *ind)
{
	int		val_sa;

	swap(lsta, 0, 0);
	val_sa = cycle_through(*lsta, index, index->index, lst_len(*lsta));
	if (val_sa > ind->val)
	{
		(*acts)++;
		ind->val = val_sa;
		if (ind->loud)
			ft_putendl_fd("sa", 1);
		return (1);
	}
	else
	{
		swap(lsta, 0, 0);
		return (0);
	}
}

static void	markup(int index, int len, t_stack *lsta, t_stack *tmp)
{
	while (len--)
	{
		if (tmp->index == index)
		{
			tmp->move = 0;
			index++;
		}
		else
			(tmp->move) = 1;
		tmp = tmp->next;
		if (!tmp)
			tmp = lsta;
	}
}

static int	moves(t_stack *index, t_stack **lsta, t_stack **lstb, t_int *ind)
{
	int		acts;
	int		len;

	acts = 0;
	len = lst_len(*lsta);
	markup(index->index, len, *lsta, index);
	while (len--)
	{
		if (check_len(&acts, index, lsta, ind))
			markup(index->index, lst_len(*lsta), *lsta, index);
		if ((*lsta)->move)
			push(lsta, lstb, 1, ind->loud);
		else
			rotate(lsta, 0, ind->loud);
		acts++;
	}
	return (acts);
}

int	act_ind(t_stack *lsta, t_stack *lstb, int index, t_int *ind)
{
	int		acts;
	t_stack	*tmp;

	tmp = lsta;
	while (index--)
		tmp = tmp->next;
	acts = moves(tmp, &lsta, &lstb, ind);
	return (acts);
}

/*printf("index	%d, val	%d\n", index, ind->val);
int	i = 0;
t_stack *temp = *lsta;
t_stack	*temp1 = *lstb;
printf("%20s", "стэк а");
printf("%21s", "стэк б\n");
while (i < lst_len(*lsta) || i < lst_len(*lstb))
{
	if (temp)
		printf("%15d", temp->index);
	if (temp1)
		printf("%15d", temp1->index);
	if (temp)
		temp = temp->next;
	if (temp1)
		temp1 = temp1->next;
	printf("\n");
	i++;
}
printf("количество действий %d\n", acts);*/

/*printf("index	%d\n", index);
int	i = 0;
t_stack *temp = lsta;
t_stack	*temp1 = lstb;
printf("%20s", "стэк а");
printf("%21s", "стэк б\n");
while (i < lst_len(lsta) || i < lst_len(lstb))
{
	if (temp)
		printf("%15d", temp->index);
	if (temp1)
		printf("%15d", temp1->index);
	if (temp)
		temp = temp->next;
	if (temp1)
		temp1 = temp1->next;
	printf("\n");
	i++;
}
printf("количество действий %d\n", acts);*/
