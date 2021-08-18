/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:02:53 by dwillard          #+#    #+#             */
/*   Updated: 2021/08/18 11:02:54 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*static void	freedom(char ***ret)
{
	int	count;

	count = 0;
	while (*ret[count])
	{
		free(*ret[count]);
		*ret[count++] = NULL;
	}
	free(*ret);
	*ret = NULL;
}*/

static void	put_ind(int **integer, int **index, char **argv)
{
	int	min;
	int	ind;
	int	min_old;
	int	count;
	int	indd;

	indd = 0;
	count = 0;
	min_old = 0x80000000;
	while (indd != count - 1)
	{
		count = 0;
		min = ft_atoi(argv[count + 1]);
		while (argv[++count])
		{
			if (min >= ft_atoi(argv[count]) && ft_atoi(argv[count]) >= min_old)
			{
				min = ft_atoi(argv[count]);
				ind = count - 1;
			}
		}
		min_old = min;
		(*integer)[ind] = min;
		(*index)[ind] = indd++;
	}
}

static int	**args(char **argv)
{
	int	counter;
	int	**ret;

	counter = 0;
	while (argv[counter])
	{
		if (!ft_isdigit(*(argv[counter])))
			return (NULL);
		counter++;
	}
	ret = malloc(sizeof(ret));
	if (!ret)
		return (NULL);
	ret[0] = malloc(sizeof(int) * counter);
	ret[1] = malloc(sizeof(int) * counter);
	ret[2] = NULL;
	if (!ret[0] || !ret[1])
		return (NULL);
	put_ind(&ret[0], &ret[1], argv);
	return (ret);
}

/*	char	**split;

 if (argc == 2)
{
	split = ft_split(argv[1], ' ');
	arr = args(split);
	freedom(&split);
}*/
t_stack	*get_args(int argc, char **argv)
{
	t_stack	*ret;
	int		**arr;

	arr = args(argv);
	ret = ft_lstnew(**arr, **(arr + 1));
	return (ret);
}
