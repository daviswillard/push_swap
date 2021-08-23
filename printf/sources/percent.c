#include "../ft_printf.h"

void	flgs_reset(t_print **flgs)
{
	(*flgs)->wdt = 0;
	(*flgs)->zero = 0;
	(*flgs)->pnt = -1;
	(*flgs)->dash = 0;
}

void	percent(char **str, const char **input, va_list args, t_print **flgs)
{
	flags(input, args, flgs);
	if (**input == 'd' || **input == 'i' || **input == 'u')
		int_case(input, str, args, flgs);
	else if (**input == 'c' || **input == '%')
		chr_case(input, str, args, flgs);
	else if (**input == 'p')
		address(input, str, args, flgs);
	else if (**input == 'x' || **input == 'X')
		sxtn_case(input, str, args, flgs);
	else
		str_case(input, str, args, flgs);
	flgs_reset(flgs);
	if ((*flgs)->error == 1)
		return ;
}
