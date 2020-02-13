/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:37:20 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/08 19:37:32 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = NULL;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if ((ret = malloc(l1 + l2 + 1)) == NULL)
		return (NULL);
	ft_strlcpy(ret, s1, l1 + 1);
	ft_strlcat(ret, s2, l1 + l2 + 1);
	return (ret);
}
