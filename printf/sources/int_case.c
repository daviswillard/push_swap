#include "../ft_printf.h"

static char	*ft_counter(long int *n, int *counter)
{
	long int	temp;
	int			ret;
	char		*ret_str;

	ret = 0;
	temp = *n;
	if (*n < 0)
		ret++;
	if (!temp)
		ret = 1;
	while (temp)
	{
		temp = temp / 10;
		ret++;
	}
	ret_str = malloc(sizeof(*ret_str) * ret + 1);
	if (!ret_str)
		return (NULL);
	ret_str[ret] = '\0';
	*counter = ret;
	return (ret_str);
}

static long int	mod_n(long int n)
{
	long int	ret;

	ret = n % 10;
	if (ret < 0)
		ret = -ret;
	return (ret);
}

static char	*ft_ltoa(long int n)
{
	int				counter;
	long int		temp;
	char			*ret;

	temp = 0;
	ret = ft_counter(&n, &counter);
	if (!ret)
		return (NULL);
	if (n < 0)
		temp = 1;
	while (--counter >= 0)
	{
		if (temp && !counter)
		{
			ret[0] = '-';
			return (ret);
		}
		ret[counter] = '0' + mod_n(n);
		n /= 10;
	}
	return (ret);
}

void	int_case(const char **input, char **str, va_list args, t_print **flgs)
{
	char			*res;
	int				integer;
	unsigned int	u_int;
	char			*fre;

	if (**input == 'd' || **input == 'i')
		integer = va_arg(args, int);
	else
		u_int = va_arg(args, int);
	if (**input == 'd' || **input == 'i')
		res = ft_ltoa(integer);
	else
		res = ft_ltoa(u_int);
	res = flagged(res, flgs, **input);
	if (!res)
	{
		(*flgs)->error = 1;
		return ;
	}
	fre = res;
	while (*res)
		*(*str)++ = *res++;
	(*input)++;
	free(fre);
}
