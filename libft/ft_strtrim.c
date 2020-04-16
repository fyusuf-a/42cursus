/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:37:59 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/16 13:50:53 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char c, char const *set)
{
	size_t	i;
	size_t	l;

	l = ft_strlen(set);
	i = 0;
	while (i < l)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s, char const *set)
{
	size_t	l;
	size_t	begin;
	size_t	end;

	if (s == NULL || set == NULL)
		return (NULL);
	l = ft_strlen(s);
	begin = 0;
	while (s[begin] && is_in(s[begin], set))
		begin++;
	if (begin == l)
		return (ft_strdup(""));
	end = l - 1;
	while (is_in(s[end], set))
		end--;
	return (ft_substr(s, begin, end - begin + 1));
}
