#include "../ft_printf.h"

static char	*zflg(char *str, int hold)
{
	char	*temp;
	char	*temp2;
	int		counter;

	counter = 0;
	temp = str;
	str = malloc(sizeof(*temp) * (hold + ft_strlen(temp) + 1));
	if (str == NULL)
		return (NULL);
	if (ft_atoi(temp) < 0 && *temp == '-')
	{
		*(ft_strchr(temp, '-')) = '0';
		str[counter++] = '-';
	}
	while (counter < hold)
		str[counter++] = '0';
	str[counter] = '\0';
	temp2 = str;
	str = ft_strjoin(str, temp);
	if (!str)
		return (NULL);
	free(temp);
	free(temp2);
	return (str);
}

static char	*wid(char *str, int hold, int dash, char input)
{
	char	*temp;
	char	*temp2;
	int		counter;

	counter = 0;
	temp = str;
	str = malloc(sizeof(*temp) * (hold + ft_strlen(temp) + 1));
	if (str == NULL)
		return (NULL);
	if (*temp == '\0' && input == 'c')
		hold -= 1;
	while (counter < hold)
		str[counter++] = ' ';
	str[counter] = '\0';
	temp2 = str;
	if (dash == 0)
		str = ft_strjoin_printf(str, temp, input);
	else
		str = ft_strjoin_printf(temp, str, input);
	free(temp);
	free(temp2);
	return (str);
}

static char	*dot(char *str, int pnt)
{
	char	*temp;
	char	*temp2;
	int		counter;

	if (pnt < 0 && *str == '0')
		return ((char *)ft_memset(str, '\0', ft_strlen(str)));
	if (pnt <= 0)
		return (str);
	counter = 0;
	temp = str;
	str = ft_calloc((pnt + 1), sizeof(*temp));
	if (str == NULL)
		return (NULL);
	if (ft_atoi(temp) < 0 && pnt > 0 && *temp == '-')
	{
		*(ft_strchr(temp, '-')) = '0';
		str[counter++] = '-';
	}
	while (counter < pnt)
		str[counter++] = '0';
	temp2 = str;
	str = ft_strjoin(str, temp);
	free(temp);
	free(temp2);
	return (str);
}

static char	*s_dot(char *str, int pnt)
{
	char	*temp;
	int		hold;

	hold = 0;
	temp = str;
	if (!pnt)
	{
		free(str);
		return (ft_strdup(""));
	}
	if (pnt > ft_strlen(str))
		return (str);
	str = malloc(sizeof(*str) * pnt);
	if (!str)
		return (NULL);
	while (hold < pnt)
	{
		str[hold] = temp[hold];
		hold++;
	}
	free(temp);
	return (str);
}

char	*flagged(char *str, t_print **flgs, char input)
{
	int	hold;

	if ((*flgs)->pnt >= 0 && str != NULL)
	{
		if (input != 's')
		{
			if (ft_atoi(str) < 0 && (input == 'd' || input == 'i'))
				str = dot(str, ((*flgs)->pnt + 1 - ft_strlen(str)));
			else
				str = dot(str, ((*flgs)->pnt) - ft_strlen(str));
		}
		if (input == 's')
			str = s_dot(str, (*flgs)->pnt);
	}
	if (ft_strlen(str) < (*flgs)->wdt && str != NULL)
	{
		hold = (*flgs)->wdt - ft_strlen(str);
		if (input != 'c' && input != 's')
			if ((*flgs)->zero != 0)
				return (zflg(str, hold));
		if ((*flgs)->wdt != 0)
			str = wid(str, hold, (*flgs)->dash, input);
	}
	return (str);
}
