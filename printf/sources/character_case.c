#include "../ft_printf.h"

void	chr_case(const char **input, char **str, va_list args, t_print **flgs)
{
	char	*ret;
	char	*fre;
	int		counter;

	ret = ft_calloc(2, sizeof(*ret));
	if (**input == 'c')
		*ret = (char)va_arg(args, int);
	else
		*ret = '%';
	ret = flagged(ret, flgs, **input);
	if (!ret)
	{
		(*flgs)->error = 1;
		return ;
	}
	counter = (*flgs)->wdt - 1;
	fre = ret;
	while (counter > 0)
	{
		*(*str)++ = *ret++;
		counter--;
	}
	*(*str)++ = *ret++;
	(*input)++;
	free(fre);
}

static void	cntr_init(int *cntr, int *cntr1, int *cntr2)
{
	*cntr = -1;
	*cntr1 = 0;
	*cntr2 = 0;
}

char	*ft_strjoin_printf(char const *s1, char const *s2, char input)
{
	int		cntr1;
	int		cntr2;
	int		cntr;
	char	*ret;

	cntr_init(&cntr, &cntr1, &cntr2);
	if (!s1 || !s2)
		return (NULL);
	if (!s1[cntr1] && !s1[cntr1 + 1] && input == 'c')
		cntr1++;
	while (s1[cntr1])
		cntr1++;
	if (!s2[cntr1] && !s2[cntr1 + 1])
		cntr2++;
	while (s2[cntr2])
		cntr2++;
	ret = ft_calloc((cntr1 + cntr2 + 1), sizeof(*ret));
	if (ret == NULL)
		return (NULL);
	while (++cntr < cntr1)
		ret[cntr] = s1[cntr];
	while (--cntr2 >= 0)
		ret[cntr + cntr2] = s2[cntr2];
	return (ret);
}
