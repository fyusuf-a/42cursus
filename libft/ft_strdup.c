/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:33:17 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/08 19:33:25 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	l;
	char	*cpy;

	cpy = NULL;
	l = ft_strlen(s);
	cpy = malloc(l + 1);
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s, l + 1);
	return (cpy);
}
