/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:41:14 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/12 12:27:58 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t i;
	size_t ls;
	size_t ld;

	ls = ft_strlen(src);
	if (dstsize == 0)
		return (ls + dstsize);
	ld = ft_strlen(dest);
	if (dstsize <= ld)
		return (ls + dstsize);
	i = ld;
	while (src[i - ld] && i < dstsize - 1)
	{
		dest[i] = src[i - ld];
		i++;
	}
	dest[i] = '\0';
	return (ls + ld);
}
