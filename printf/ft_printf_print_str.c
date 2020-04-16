/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:55:46 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/02/08 18:02:10 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void
	load_params(t_print_params *params, const t_format *format, char *str)
{
	int strlen;

	if (format->type == STRING)
	{
		strlen = 0;
		while (str[strlen])
			strlen++;
		params->len_proper = strlen;
	}
	else
		params->len_proper = 1;
	if (format->type == STRING && format->precision != -1
			&& params->len_proper >= format->precision)
		params->len_proper = format->precision;
	params->len_padding = 0;
	if (format->width != -1 && format->width > params->len_proper)
		params->len_padding = format->width - params->len_proper;
}

static void
	print_str_using_buffer(char *str, t_print_params *params)
{
	int	i;

	i = 0;
	while (i < params->len_proper)
		load_buffer(str[i++]);
}

void
	print_str_acc(char *str, const t_format *format)
{
	t_print_params	params;

	load_params(&params, format, str);
	if (format->minus)
	{
		print_str_using_buffer(str, &params);
		print_padding(format, params.len_padding);
	}
	else
	{
		print_padding(format, params.len_padding);
		print_str_using_buffer(str, &params);
	}
}

void
	print_str(va_list *args, t_format *format)
{
	char			*str;

	if (!(str = va_arg(*args, char*)))
		str = "(null)";
	print_str_acc(str, format);
}

void
	print_char(va_list *args, t_format *format, t_buff *str)
{
	t_print_params	params;
	char			c;
	char			string[1];

	if (format->type == CHAR)
		c = (char)va_arg(*args, int);
	else if (format->type == UNKNOWN_TYPE)
		c = str->buffer[str->cursor - 1];
	else
		c = '%';
	load_params(&params, format, string);
	if (format->minus)
	{
		load_buffer(c);
		print_padding(format, params.len_padding);
	}
	else
	{
		print_padding(format, params.len_padding);
		load_buffer(c);
	}
}
