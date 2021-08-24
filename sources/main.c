/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:00:22 by dwillard          #+#    #+#             */
/*   Updated: 2021/08/18 11:00:24 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stka;
	t_stack	*stkb;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	stka = get_args(argc, argv);
	algs(argc - 1, &stka, &stkb);
	return (0);
}
