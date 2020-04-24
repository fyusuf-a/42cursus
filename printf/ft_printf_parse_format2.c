/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_format2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:30:03 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/24 13:30:07 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	ft_printf_parse_modifier(t_ft_printf_format *format,
			t_ft_printf_format_str *st)
{
	if (st->buffer[st->cursor] == 'l')
	{
		format->modifier = LONG;
		st->cursor++;
		if (st->buffer[st->cursor] == 'l')
		{
			format->modifier = LONG_LONG;
			st->cursor++;
		}
	}
}

void
	ft_printf_parse_type(t_ft_printf_format *format, t_ft_printf_format_str *st)
{
	char c;

	c = st->buffer[st->cursor];
	format->type = UNKNOWN_TYPE;
	c == 'c' ? format->type = CHAR : 0;
	c == 's' ? format->type = STRING : 0;
	c == 'p' ? format->type = POINTER : 0;
	c == 'd' ? format->type = INT : 0;
	c == 'i' ? format->type = INT : 0;
	c == 'u' ? format->type = UNSIGNED_INT : 0;
	c == 'x' ? format->type = HEXA_MIN : 0;
	c == 'X' ? format->type = HEXA_MAJ : 0;
	c == '%' ? format->type = PERCENTAGE : 0;
	c == 'n' ? format->type = NOTHING : 0;
	c == 'f' ? format->type = DOUBLE : 0;
	c == 'e' ? format->type = SCIENTIFIC : 0;
	c == 'g' ? format->type = G : 0;
	st->cursor++;
}
