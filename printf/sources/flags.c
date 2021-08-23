#include "../ft_printf.h"

static int	nuldsh(const char **input)
{
	int		counter;
	int		cntr;
	char	*holder;
	char	*ret;

	counter = 0;
	cntr = 0;
	while ((*input)[counter] >= '0' && (*input)[counter] <= '9')
		counter++;
	holder = ft_calloc(counter + 1, sizeof(*holder));
	if (!holder)
		return (-1);
	ret = holder;
	while (cntr < counter)
		*holder++ = (*input)[cntr++];
	*input += cntr;
	counter = ft_atoi(ret);
	free(ret);
	return (counter);
}

static int	starred(const char **input, va_list args)
{
	char	temp;

	temp = **input;
	if (ft_isdigit(**input))
		return (nuldsh(input));
	(*input)++;
	if (**input == '*' || temp == '*')
		return (va_arg(args, int));
	if (temp == '.' && !ft_isdigit(**input))
		return (0);
	return (nuldsh(input));
}

void	flags(const char **input, va_list args, t_print **flgs)
{
	(*input)++;
	while (!ft_isalpha(**input) && **input != '%')
	{
		if (*(*input) == '-')
			(*flgs)->dash = 1;
		if (*(*input) == '0')
			(*flgs)->zero = 1;
		if ((**input >= '1' && **input <= '9') || **input == '*')
			(*flgs)->wdt = starred(input, args);
		if (**input == '.')
			(*flgs)->pnt = starred(input, args);
		if (!ft_isalpha(**input) && **input != '%')
			(*input)++;
	}
	if ((*flgs)->wdt < 0)
	{
		(*flgs)->dash = 1;
		(*flgs)->wdt = -(*flgs)->wdt;
	}
	if ((*flgs)->dash || (*flgs)->pnt >= 0)
		(*flgs)->zero = 0;
}
