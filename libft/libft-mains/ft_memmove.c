/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:23:45 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/08 19:11:57 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	dst2 = (char*)dst;
	src2 = (char*)src;
	i = 0;
	while (i < len)
	{
		if (src < dst)
			dst2[len - 1 - i] = src2[len - 1 - i];
		else
			dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
