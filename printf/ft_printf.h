#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_print
{
	int		wdt;
	int		zero;
	int		pnt;
	int		dash;
	int		error;
}				t_print;

int		ft_printf(const char *input, ...);

char	*ft_strjoin_printf(char const *s1, char const *s2, char input);

int		works(const char *input, va_list args, t_print **flgs);

void	percent(char **str, const char **input, va_list args, t_print **flgs);

void	int_case(const char **input, char **str, va_list args, t_print **flgs);

void	sxtn_case(const char **input, char **str, va_list args, t_print **flgs);

void	address(const char **input, char **str, va_list args, t_print **flgs);

void	chr_case(const char **input, char **str, va_list args, t_print **flgs);

void	str_case(const char **input, char **str, va_list args, t_print **flgs);

void	flags(const char **input, va_list args, t_print **flgs);

char	*flagged(char *str, t_print **flgs, char input);

#endif
