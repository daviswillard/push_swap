/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:16:13 by dwillard          #+#    #+#             */
/*   Updated: 2021/09/21 13:16:15 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*пара функций, считающих шаги для сортировки стэка а при использовании
 * rotate и r_rotate соответственно*/
static int	rotater(t_stack *lst, int befor, int after)
{
	int		ret;

	ret = 0;
	while (lst->index < befor || lst->index > after)
	{
		ret++;
		rotate(&lst, 0, 0);
	}
	return (ret);
}

static int	r_rotater(t_stack *lst, int befor, int after)
{
	int		ret;

	ret = 0;
	while (lst->index < befor || lst->index > after)
	{
		ret++;
		r_rotate(&lst, 0, 0);
	}
	return (ret);
}

/*mem is allocated in this function: be careful!*/

/*пара функций, которые должны посчитать кол-во ходов для сортировки стэка а*/

int	*moves_to_a_2(t_stack *lsta, int index)
{
	int		*moves;
	int		befor;
	int		after;
	t_stack	*temp;
	t_stack	*temp2;

	befor = -1;
	after = 0x7fffffff;
	while (lsta)
	{
		if (lsta->index < index && befor < lsta->index)
			befor = lsta->index;
		if (lsta->index > index && after > lsta->index)
			after = lsta->index;
		lsta = lsta->next;
	}
	temp = ft_lstcpy(lsta);
	temp2 = ft_lstcpy(lsta);
	moves = ft_calloc(4, 4);
	moves[0] = rotater(temp, befor, after);
	moves[1] = r_rotater(temp2, befor, after);
	ft_lstclr(&temp);
	ft_lstclr(&temp2);
	return (moves);
}

int	*moves_to_a(t_stack *lsta)
{
	int		min;
	int		*moves;
	t_stack	*temp;
	t_stack	*temp2;

	min = 0x7fffffff;
	temp = ft_lstcpy(lsta);
	moves = ft_calloc(4, 4);
	temp2 = temp;
	while (temp2)
	{
		if (min > temp2->index)
			min = temp2->index;
		temp2 = temp2->next;
	}
	temp2 = ft_lstcpy(lsta);
	while (temp->index != min && moves[0]++ > -1)
		rotate(&temp, 1, 0);
	while (temp2->index != min && moves[1]++ > -1)
		r_rotate(&temp2, 0, 0);
	ft_lstclr(&temp);
	ft_lstclr(&temp2);
	return (moves);
}
