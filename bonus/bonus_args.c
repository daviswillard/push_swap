/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:07:52 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/11 14:30:34 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

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
		(*index)[ind] = counter;
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
		if (argv[counter][0] == '-' && !ft_isdigit(argv[counter][1]))
			return (NULL);
		counter++;
	}
	ret = malloc(sizeof(int *) * counter * 2);
	if (!ret)
		exit(-1);
	ret[0] = ft_calloc(counter, sizeof(int));
	ret[1] = ft_calloc(counter, sizeof(int));
	ret[2] = NULL;
	if (!ret[0] || !ret[1])
		exit(1);
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
	if (arr == NULL)
	{
		ft_putendl_fd("Error", 2);
		exit(-1);
	}
	ret = ft_lstnew(arr[0][0], arr[1][0]);
	while (index < argc - 1)
	{
		ft_lstadd_back(&ret, ft_lstnew(arr[0][index], arr[1][index]));
		index++;
	}
	free(arr[0]);
	free(arr[1]);
	free(arr);
	return (ret);
}
