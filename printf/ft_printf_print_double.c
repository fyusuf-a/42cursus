/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_double.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:02:46 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/16 13:47:06 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void
	load_params(t_print_params *params, const t_format *format,
								double x, int sign)
{
	int	len;

	params->len_padding = 0;
	len = x < 1 ? 1 : first_digit_exponent(x) + 1;
	len += sign;
	len += (format->plus && !sign ? 1 : 0);
	if (format->precision == -1)
		len += 7;
	else if (format->precision > 0)
		len += format->precision + 1;
	if (format->width != -1 && format->width > len)
		params->len_padding = format->width - len;
}

static void
	print_double_absolute_value(double x, const t_format *format)
{
	int						number_of_decimals;
	double					decimal_part;

	decimal_part = (x - (int)x) * 10;
	number_of_decimals = format->precision == -1 ? 6 : format->precision;
	print_integer_part((unsigned long long)x);
	if (number_of_decimals != 0)
	{
		load_buffer('.');
		print_decimal_part(decimal_part, number_of_decimals);
	}
}

void
	print_double_acc(double x, const t_format *format)
{
	t_print_params	params;
	int				sign;

	sign = x < 0.0 ? 1 : 0;
	x = x < 0.0 ? -x : x;
	if (format->type != G)
		round_double(&x, format->precision == -1 ? 6 : format->precision);
	load_params(&params, format, x, sign);
	if (format->minus)
	{
		sign ? load_buffer('-') : 0;
		!sign && format->plus ? load_buffer('+') : 0;
		print_double_absolute_value(x, format);
		print_padding(format, params.len_padding);
	}
	else
	{
		if (format->padding != '0')
			print_padding(format, params.len_padding);
		sign ? load_buffer('-') : 0;
		!sign && format->plus ? load_buffer('+') : 0;
		if (format->padding == '0')
			print_padding(format, params.len_padding);
		print_double_absolute_value(x, format);
	}
}

void
	print_double(va_list *args, t_format *format)
{
	double			x;

	x = va_arg(*args, double);
	if (x == 5.0 / 0.0 || x == -5.0 / 0.0 || x != x)
	{
		format->padding = ' ';
		format->type = STRING;
		format->precision = 4;
		if (x != x)
			print_str_acc("nan", format);
		else if (format->plus && x > 0)
			print_str_acc("+inf", format);
		else
			x > 0 ? print_str_acc("inf", format) :
						print_str_acc("-inf", format);
	}
	else
	{
		if (format->type == DOUBLE)
			print_double_acc(x, format);
		else if (format->type == SCIENTIFIC)
			print_scientific_acc(x, format);
		else
			print_g_acc(x, format);
	}
}
