/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:55:46 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/06/29 11:39:05 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void
	ft_printf_load_params(t_ft_printf_print_params *params,
			const t_ft_printf_format *format, char *str)
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
	ft_printf_print_str_using_buffer(char *str,
			t_ft_printf_print_params *params)
{
	int	i;

	i = 0;
	while (i < params->len_proper)
		ft_printf_load_buffer(str[i++]);
}

void
	ft_printf_print_str_acc(char *str, const t_ft_printf_format *format)
{
	t_ft_printf_print_params	params;

	ft_printf_load_params(&params, format, str);
	if (format->minus)
	{
		ft_printf_print_str_using_buffer(str, &params);
		ft_printf_print_padding(format, params.len_padding);
	}
	else
	{
		ft_printf_print_padding(format, params.len_padding);
		ft_printf_print_str_using_buffer(str, &params);
	}
}

void
	ft_printf_print_str(va_list *args, t_ft_printf_format *format)
{
	char			*str;

	if (!(str = va_arg(*args, char*)))
		str = "(null)";
	ft_printf_print_str_acc(str, format);
}

void
	ft_printf_print_char(va_list *args, t_ft_printf_format *format,
			t_ft_printf_format_str *str)
{
	t_ft_printf_print_params	params;
	char						string[1];

	if (format->type == CHAR)
		string[0] = (char)va_arg(*args, int);
	else if (format->type == UNKNOWN_TYPE)
		string[0] = str->buffer[str->cursor - 1];
	else
		string[0] = '%';
	ft_printf_load_params(&params, format, string);
	if (format->minus)
	{
		ft_printf_load_buffer(string[0]);
		ft_printf_print_padding(format, params.len_padding);
	}
	else
	{
		ft_printf_print_padding(format, params.len_padding);
		ft_printf_load_buffer(string[0]);
	}
}
