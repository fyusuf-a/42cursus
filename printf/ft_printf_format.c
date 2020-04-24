/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:24:02 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/24 13:31:12 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_printf_flush_format(t_ft_printf_format_str *str)
{
	char c;

	while ((c = str->buffer[str->cursor]) && c != '%')
	{
		ft_printf_load_buffer(c);
		str->cursor++;
	}
	if (!c)
		return (-1);
	str->cursor++;
	return (0);
}

void
	ft_printf_initialize_format(t_ft_printf_format *format)
{
	format->minus = 0;
	format->plus = 0;
	format->sharp = 0;
	format->padding = ' ';
	format->width = -1;
	format->precision = -1;
	format->modifier = NO_MODIFIER;
}
