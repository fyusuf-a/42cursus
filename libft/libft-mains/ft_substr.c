/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:36:46 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/10 16:53:03 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	l;

	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	if (start > l - 1)
		return (ft_strdup(""));
	if ((ret = malloc(len + 1)) == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
