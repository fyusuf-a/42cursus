/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:29:27 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/12 16:00:28 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	result;
	int	sep_before;

	result = 0;
	sep_before = 1;
	while (*str)
	{
		if (*str == c)
			sep_before = 1;
		else
		{
			if (sep_before)
				result++;
			sep_before = 0;
		}
		str++;
	}
	return (result);
}

static char	*fill_and_consume(char **str, char c)
{
	int		l;
	int		i;
	char	*result;

	l = 0;
	while ((*str)[l] && (*str)[l] != c)
		l++;
	result = (char*)malloc((l + 1) * sizeof(char));
	result[l] = '\0';
	i = 0;
	while (i < l)
	{
		result[i] = **str;
		(*str)++;
		i++;
	}
	return (result);
}

static void	eat_char(char **str, char c)
{
	while (**str && **str == c)
		(*str)++;
}

char		**ft_split(char const *str, char c)
{
	char	**result;
	char	*str2;
	int		count;
	int		i;

	if (str == NULL)
		return (NULL);
	count = count_words(str, c);
	result = NULL;
	result = (char**)malloc((count + 1) * sizeof(char*));
	if (result == NULL)
		return (NULL);
	result[count] = NULL;
	str2 = (char*)str;
	eat_char(&str2, c);
	i = 0;
	while (i < count)
	{
		result[i] = fill_and_consume(&str2, c);
		eat_char(&str2, c);
		i++;
	}
	return (result);
}
