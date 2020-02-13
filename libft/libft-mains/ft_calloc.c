/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:32:56 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/11 14:35:01 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = NULL;
	ret = malloc(size * count * sizeof(char));
	if (!ret)
		return (NULL);
	ft_bzero(ret, size * count);
	return (ret);
}
