/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_double.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:02:46 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/16 17:14:09 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void
	load_params(t_ft_printf_print_params *params,
			const t_ft_printf_format *format, double x, int sign)
{
	int	len;

	params->len_padding = 0;
	len = x < 1 ? 1 : ft_printf_first_digit_exponent(x) + 1;
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
	print_double_absolute_value(double x, const t_ft_printf_format *format)
{
	int						number_of_decimals;
	double					decimal_part;

	decimal_part = (x - (int)x) * 10;
	number_of_decimals = format->precision == -1 ? 6 : format->precision;
	ft_printf_print_integer_part((unsigned long long)x);
	if (number_of_decimals != 0)
	{
		ft_printf_load_buffer('.');
		ft_printf_print_decimal_part(decimal_part, number_of_decimals);
	}
}

static int
	initialize_sign_absolute_value(double *x)
{
	int sign;

	sign = *x < 0.0 ? 1 : 0;
	*x = *x < 0.0 ? -*x : *x;
	return (sign);
}

void
	ft_printf_print_double_acc(double x, const t_ft_printf_format *format)
{
	t_ft_printf_print_params	params;
	int							sign;

	sign = initialize_sign_absolute_value(&x);
	if (format->type != G)
		ft_printf_round_double(&x, format->precision == -1 ? 6 :
				format->precision);
	load_params(&params, format, x, sign);
	if (format->minus)
	{
		sign ? ft_printf_load_buffer('-') : 0;
		!sign && format->plus ? ft_printf_load_buffer('+') : 0;
		print_double_absolute_value(x, format);
		ft_printf_print_padding(format, params.len_padding);
	}
	else
	{
		if (format->padding != '0')
			ft_printf_print_padding(format, params.len_padding);
		sign ? ft_printf_load_buffer('-') : 0;
		!sign && format->plus ? ft_printf_load_buffer('+') : 0;
		if (format->padding == '0')
			ft_printf_print_padding(format, params.len_padding);
		print_double_absolute_value(x, format);
	}
}

void
	ft_printf_print_double(va_list *args, t_ft_printf_format *format)
{
	double			x;

	x = va_arg(*args, double);
	if (x == 5.0 / 0.0 || x == -5.0 / 0.0 || x != x)
	{
		format->padding = ' ';
		format->type = STRING;
		format->precision = 4;
		if (x != x)
			ft_printf_print_str_acc("nan", format);
		else if (format->plus && x > 0)
			ft_printf_print_str_acc("+inf", format);
		else
			x > 0 ? ft_printf_print_str_acc("inf", format) :
						ft_printf_print_str_acc("-inf", format);
	}
	else
	{
		if (format->type == DOUBLE)
			ft_printf_print_double_acc(x, format);
		else if (format->type == SCIENTIFIC)
			ft_printf_print_scientific_acc(x, format);
		else
			ft_printf_print_g_acc(x, format);
	}
}
