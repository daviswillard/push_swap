#include "../ft_printf.h"

static void	flgs_init(t_print **flgs)
{
	*flgs = malloc(sizeof(t_print));
	if (*flgs)
	{
		(*flgs)->wdt = 0;
		(*flgs)->zero = 0;
		(*flgs)->pnt = -1;
		(*flgs)->dash = 0;
		(*flgs)->error = 0;
	}
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int			ret;
	t_print		*flgs;

	flgs_init(&flgs);
	if (!flgs)
		return (-1);
	va_start(args, input);
	ret = works(input, args, &flgs);
	va_end(args);
	free(flgs);
	return (ret);
}
