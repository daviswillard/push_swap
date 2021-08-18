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
#include <stdio.h>

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

static void	put_ind(int **integer, int **index, char **argv, int argc)
{
	int	ind;
	int	counter;
	int	counter2;

	ind = 0;
	while (ind < argc - 1)
	{
		counter = 0;
		counter2 = 0;
		(*integer)[ind] = ft_atoi(argv[ind + 1]);
		while (++counter2 < argc)
			if ((*integer)[ind] > ft_atoi(argv[counter2]))
				counter++;
		(*index)[ind] = counter + 1;
		ind++;
	}
}

static int	**args(char **argv, int argc)
{
	int	counter;
	int	**ret;

	counter = 1;
	while (argv[counter])
	{
		if (!ft_isdigit(*(argv[counter])) && *(argv[counter]) != '-')
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
	put_ind(&ret[0], &ret[1], argv, argc);
	return (ret);
}

t_stack	*get_args(int argc, char **argv)
{
	t_stack	*ret;
	int		**arr;
	int		index;

	index = 1;
	arr = args(argv, argc);
	ret = ft_lstnew(arr[0][0], arr[1][0]);
	while (index < argc - 1)
	{
		ft_lstadd_back(&ret, ft_lstnew(arr[0][index], arr[1][index]));
		index++;
	}
	return (ret);
}
