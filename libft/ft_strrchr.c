/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:15:00 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/08 19:15:07 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*needle;

	needle = NULL;
	while (*s)
	{
		if (*s == c)
			needle = (char*)s;
		s++;
	}
	if (*s == c)
		needle = (char*)s;
	return (needle);
}
