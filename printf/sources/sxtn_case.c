#include "../ft_printf.h"

static int	counter(unsigned int integer)
{
	int				count;
	unsigned int	temp;

	count = 0;
	temp = integer;
	if (!temp)
		return (1);
	while (temp)
	{
		count++;
		temp /= 16;
	}
	return (count);
}

static char	letter(unsigned int temp, char inp)
{
	char	symbol;

	if (!(temp / 10))
		symbol = temp + '0';
	else if (inp == 'x')
		symbol = (temp % 10) + 'a';
	else
		symbol = (temp % 10) + 'A';
	return (symbol);
}

static char	*converter(unsigned int integer, char inp)
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
		string[quantity] = letter(temp, inp);
		integer /= 16;
		quantity--;
	}
	string[quantity] = letter(integer, inp);
	return (string);
}

void	sxtn_case(const char **input, char **str, va_list args, t_print **flgs)
{
	unsigned int		calc;
	char				*ret;
	char				*fre;

	calc = va_arg(args, unsigned int);
	ret = converter(calc, **input);
	ret = flagged(ret, flgs, **input);
	if (!ret)
	{
		(*flgs)->error = 1;
		return ;
	}
	fre = ret;
	while (*ret)
		*(*str)++ = *ret++;
	(*input)++;
	free(fre);
}
