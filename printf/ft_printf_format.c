/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:24:02 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/01/28 13:18:41 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	flush_format(t_buff *str)
{
	char c;

	while ((c = str->buffer[str->cursor]) && c != '%')
	{
		load_buffer(c);
		str->cursor++;
	}
	if (!c)
		return (-1);
	str->cursor++;
	return (0);
}

void
	initialize_format(t_format *format)
{
	format->minus = 0;
	format->plus = 0;
	format->sharp = 0;
	format->padding = ' ';
	format->width = -1;
	format->precision = -1;
	format->modifier = NO_MODIFIER;
}
