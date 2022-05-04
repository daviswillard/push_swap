/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:08:01 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/11 15:32:24 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void	rr(t_stack **lsta, t_stack **lstb)
{
	rotate_bon(lsta);
	rotate_bon(lstb);
}

static void	rrr(t_stack **lsta, t_stack **lstb)
{
	r_rotate_bon(lsta);
	r_rotate_bon(lstb);
}

static void	do_cmds(t_stack **lsta, t_stack **lstb, char *line)
{
	if (!ft_strncmp(line, "sa", ft_strlen(line)))
		swap_bon(lsta);
	else if (!ft_strncmp(line, "sb", ft_strlen(line)))
		swap_bon(lstb);
	else if (!ft_strncmp(line, "pa", ft_strlen(line)))
		push_bon(lstb, lsta);
	else if (!ft_strncmp(line, "pb", ft_strlen(line)))
		push_bon(lsta, lstb);
	else if (!ft_strncmp(line, "ra", ft_strlen(line)))
		rotate_bon(lsta);
	else if (!ft_strncmp(line, "rb", ft_strlen(line)))
		rotate_bon(lstb);
	else if (!ft_strncmp(line, "rr", ft_strlen(line)))
		rr(lsta, lstb);
	else if (!ft_strncmp(line, "rra", ft_strlen(line)))
		r_rotate_bon(lsta);
	else if (!ft_strncmp(line, "rrb", ft_strlen(line)))
		r_rotate_bon(lstb);
	else if (!ft_strncmp(line, "rrr", ft_strlen(line)))
		rrr(lsta, lstb);
	else
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
}

void	get_push_swap(t_stack **lsta, t_stack **lstb)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		do_cmds(lsta, lstb, line);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}
