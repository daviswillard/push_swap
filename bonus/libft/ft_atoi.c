/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:02:55 by dwillard          #+#    #+#             */
/*   Updated: 2021/04/21 13:38:16 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	spacer(char input)
{
	if (input == '\n')
		return ('\n');
	if (input == '\t')
		return ('\t');
	if (input == '\v')
		return ('\v');
	if (input == '\r')
		return ('\r');
	if (input == ' ')
		return (' ');
	if (input == '\f')
		return ('\f');
	return (' ');
}

static void	check_push_swap(long value, int ind, const char *str, int sgn)
{
	char	check;
	int		index;

	index = 0;
	check = str[ind];
	if (sgn < 0)
		value = -value;
	if (check != '\0' || (value > 2147483647 || value < -2147483648))
	{
		ft_putendl_fd("Error", 2);
		exit (0);
	}
	while (!ft_isdigit(str[index]))
		index++;
	if (ind - index > 10)
	{
		ft_putendl_fd("Error", 2);
		exit (0);
	}
}

int	ft_atoi(const char *str)
{
	int		ind;
	int		sgn;
	long	value;

	sgn = 1;
	ind = 0;
	value = 0;
	while (spacer(str[ind]) == str[ind])
		ind++;
	if (str[ind] == '-' || str[ind] == '+')
	{
		if (str[ind] == '-')
			sgn = -1;
		ind++;
	}
	while (str[ind] >= 48 && str[ind] <= 57)
	{
		value *= 10;
		value += (str[ind] - 48);
		ind++;
	}
	check_push_swap(value, ind, str, sgn);
	if (sgn == -1)
		value = -value;
	return ((int)value);
}
