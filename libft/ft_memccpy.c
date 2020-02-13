/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:59:04 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/08 18:59:11 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	if (src == NULL && dst == NULL)
		return (NULL);
	src2 = (unsigned char*)src;
	dst2 = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		*dst2 = *src2;
		if (*src2 == (unsigned char)c)
		{
			dst2++;
			return (dst2);
		}
		dst2++;
		src2++;
		i++;
	}
	return (NULL);
}
