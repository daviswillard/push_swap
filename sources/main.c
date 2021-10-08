/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:00:22 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/08 14:42:06 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	freed(char ***obj)
{
	int	index;

	index = 0;
	while ((*obj)[index])
	{
		free((*obj)[index]);
		(*obj)[index] = NULL;
		index++;
	}
	free(*obj);
	*obj = NULL;
}

static void	check_digits(int count, char **ret)
{
	int		index;
	int		ind;

	index = 0;
	ind = 0;
	while (++index < count)
	{
		while (ret[index][ind] != '\0')
		{
			if (!ft_isdigit(ret[index][ind]) && ret[index][ind] != '-')
			{
				ft_putendl_fd("Error", 1);
				exit(0);
			}
			if (ret[index][ind] == '-' && ind > 0 && ret[index][ind - 1] == '-')
			{
				ft_putendl_fd("Error", 1);
				exit(0);
			}
			ind++;
		}
		ind = 0;
	}
}

static char	**parse_str(int *count, char *argv)
{
	char	**ret;

	*count = 0;
	argv = ft_strjoin("push_swap ", argv);
	ret = ft_split(argv, ' ');
	while (ret[*count])
		(*count)++;
	free(argv);
	if (*count == 1)
	{
		ft_putendl_fd("Error", 1);
		exit(0);
	}
	check_digits(*count, ret);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_stack	*stka;
	t_stack	*stkb;
	char	**integers;
	int		count;

	stkb = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	count = argc;
	if (count == 2)
	{
		integers = parse_str(&count, argv[1]);
		stka = get_args(count, integers);
		freed(&integers);
	}
	else
		stka = get_args(argc, argv);
	algs(&stka, &stkb);
	return (0);
}
