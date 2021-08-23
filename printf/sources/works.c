#include "../ft_printf.h"

static void	ft_putstr_quant(const char *s, int quant)
{
	write(1, s, quant);
}

int	works(const char *input, va_list args, t_print **flgs)
{
	char	*str;
	char	*str_cmp;
	int		ret;

	str = ft_calloc(4096, sizeof(*str));
	if (!str)
		return (-1);
	str_cmp = str;
	while (*input)
	{
		if (*input != '%')
			*str++ = *input++;
		else
			percent(&str, &input, args, flgs);
		if ((*flgs)->error == 1)
		{
			free(str_cmp);
			return (-1);
		}
	}
	ret = (int)(str - str_cmp);
	ft_putstr_quant(str_cmp, ret);
	free(str_cmp);
	return (ret);
}
