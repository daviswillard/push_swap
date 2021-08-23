#include "../ft_printf.h"

void	str_case(const char **input, char **str, va_list args, t_print **flgs)
{
	char	*s;
	char	*fre;

	s = va_arg(args, char *);
	if (s)
		s = ft_strdup(s);
	else
		s = ft_strdup("(null)");
	s = flagged(s, flgs, **input);
	if (!s)
	{
		(*flgs)->error = 1;
		return ;
	}
	fre = s;
	while (*s)
		*(*str)++ = *s++;
	(*input)++;
	free(fre);
}
