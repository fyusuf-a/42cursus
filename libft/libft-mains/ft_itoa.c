/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:42:46 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/08 18:24:23 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length(int n)
{
	size_t length;

	length = 1;
	while (n >= 10)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static void		fill(char *ret, size_t l, size_t sign, int n)
{
	size_t	i;

	i = 1;
	while (i <= l)
	{
		ret[sign + l - i] = '0' + n % 10;
		n = n / 10;
		i++;
	}
	ret[sign + l] = '\0';
}

char			*ft_itoa(int n)
{
	size_t	sign;
	char	*ret;
	size_t	l;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	ret = NULL;
	l = length(n);
	if (!(ret = (char*)malloc(sign + l + 1)))
		return (NULL);
	if (sign)
		ret[0] = '-';
	fill(ret, l, sign, n);
	return (ret);
}
