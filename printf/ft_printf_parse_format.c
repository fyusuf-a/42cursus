/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:43:20 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/24 13:27:36 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void
	parse_flags(t_ft_printf_format *format, t_ft_printf_format_str *str)
{
	char c;

	while ((c = str->buffer[str->cursor]))
	{
		if (c == '-')
			format->minus = 1;
		else if (c == '+')
			format->plus = 1;
		else if (c == '#')
			format->sharp = 1;
		else if (c == '0')
			format->padding = '0';
		else
			break ;
		str->cursor++;
	}
}

static int
	parse_width(t_ft_printf_format *format, va_list *args,
			t_ft_printf_format_str *str)
{
	int				w;

	if ((format->width =
				ft_printf_atoi_strict(str->buffer + str->cursor)) != -1)
		ft_printf_advance_cursor(str, ft_printf_ilen(format->width, 10));
	if (str->buffer[str->cursor] == '*')
	{
		w = va_arg(*args, int);
		if (w < 0)
		{
			format->width = -w;
			format->minus = 1;
			format->padding = ' ';
		}
		else
			format->width = w;
		str->cursor++;
	}
	else if (!str->buffer[str->cursor])
		return (-1);
	return (0);
}

static void
	parse_precision(t_ft_printf_format *format, va_list *args,
			t_ft_printf_format_str *str)
{
	if (str->buffer[str->cursor] == '*')
	{
		format->precision = va_arg(*args, int);
		if (format->precision < 0)
			format->precision = -1;
		str->cursor++;
	}
	else if ((format->precision =
					ft_printf_atoi_strict(str->buffer + str->cursor)) == -1)
		format->precision = 0;
	else
		ft_printf_advance_cursor(str, ft_printf_ilen(format->precision, 10));
}

/*
** Returns -1 if cannot parse 0 otherwise
*/

int
	ft_printf_parse_format(t_ft_printf_format *format,
			va_list *args, t_ft_printf_format_str *str)
{
	parse_flags(format, str);
	if (parse_width(format, args, str) < 0)
		return (-1);
	if (str->buffer[str->cursor] == '.')
	{
		str->cursor++;
		parse_precision(format, args, str);
	}
	else if (!str->buffer[str->cursor])
		return (-1);
	ft_printf_parse_modifier(format, str);
	ft_printf_parse_type(format, str);
	if (format->padding == '0' && format->precision >= 0
				&& format->type != DOUBLE && format->type != SCIENTIFIC
				&& format->type != G)
		format->padding = ' ';
	return (0);
}
