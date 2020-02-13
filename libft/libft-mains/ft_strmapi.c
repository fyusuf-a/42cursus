/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:38:26 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/08 19:38:47 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (!(ret = ft_strdup(s)))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		ret[i] = (*f)(i, ret[i]);
		i++;
	}
	return (ret);
}
