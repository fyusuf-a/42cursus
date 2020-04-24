/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:14:27 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/24 09:27:53 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_printf(const char *str, ...)
{
	va_list	args;
	int		ret;

	va_start(args, str);
	ret = ft_zprintf(1, str, &args);
	va_end(args);
	return (ret);
}

int
	ft_dprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		ret;

	va_start(args, str);
	ret = ft_zprintf(fd, str, &args);
	va_end(args);
	return (ret);
}
