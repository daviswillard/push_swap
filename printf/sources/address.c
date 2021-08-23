#include "../ft_printf.h"

static int	counter(unsigned long integer)
{
	int				count;
	unsigned long	temp;

	count = 0;
	temp = integer;
	while (temp)
	{
		count++;
		temp /= 16;
	}
	return (count);
}

static char	letter(unsigned long temp)
{
	char	symbol;

	if (!(temp / 10))
		symbol = temp + '0';
	else
		symbol = (temp % 10) + 'a';
	return (symbol);
}

static char	*converter(unsigned long integer)
{
	int		quantity;
	int		temp;
	char	*string;

	quantity = counter(integer);
	string = malloc(sizeof(*string) * quantity + 1);
	if (!string)
		return (NULL);
	string[quantity--] = '\0';
	while (quantity > 0)
	{
		temp = (integer % 16);
		string[quantity] = letter(temp);
		integer /= 16;
		quantity--;
	}
	string[quantity] = letter(integer);
	return (string);
}

void	address(const char **input, char **str, va_list args, t_print **flgs)
{
	unsigned long		calc;
	char				*ret;
	char				*temp;
	char				*pre;

	pre = "0x";
	calc = (unsigned long)va_arg(args, void *);
	if (!calc)
		ret = ft_strdup("0");
	else
		ret = converter(calc);
	temp = ret;
	ret = ft_strjoin(pre, temp);
	ret = flagged(ret, flgs, **input);
	free(temp);
	if (!ret || !temp)
	{
		(*flgs)->error = 1;
		return ;
	}
	temp = ret;
	while (*ret)
		*(*str)++ = *ret++;
	(*input)++;
	free(temp);
}
