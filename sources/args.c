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

static void	freedom(char ***ret)
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
}

static void	put_ind(int **integer, int **index, char **argv)
{
	int	min;
	int ind;

	index = 0;
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

t_stack	*get_args(int argc, char **argv)
{
	t_stack	*ret;
	int		**arr;
	char	**split;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		arr = args(split);
		freedom(&split);
	}
	else
		arr = args(argv);
	ret = ft_lstnew('a','b');
	return (ret);
}
