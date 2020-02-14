/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scientific.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:08:14 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/02/13 16:08:07 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void
	load_params(t_print_params *params, const t_format *format,
								double x, int sign)
{
	int	len;

	params->len_padding = 0;
	len = 1;
	len += sign;
	len += (format->plus && !sign ? 1 : 0);
	len += 1;
	if (format->precision == -1)
		len += 6;
	else if (format->precision > 0)
		len += format->precision;
	len += 2 + (first_digit_exponent(x) >= 100 ? 3 : 2);
	if (format->width != -1 && format->width > len)
		params->len_padding = format->width - len;
}

static void
	load_format(t_format *format, int exponent)
{
	format->minus = 0;
	format->plus = 1;
	format->sharp = 0;
	format->padding = ' ';
	format->width = -1;
	format->precision = exponent >= 100 ? 3 : 2;
	format->modifier = NO_MODIFIER;
	format->type = INT;
}

static void
	print_scientific_absolute_value(double x, const t_format *format)
{
	int			exponent;
	int			i;
	t_integer	n;
	t_format	format_exponent;

	exponent = first_digit_exponent(x);
	x = x * power(10, -exponent);
	load_buffer('0' + (int)x);
	if (format->precision > 0)
		load_buffer('.');
	i = 0;
	while (i < (format->precision == -1 ? 6 : format->precision))
	{
		x = 10 * (x - (int)x);
		load_buffer('0' + (int)x);
		i++;
	}
	load_buffer('e');
	n.abs = exponent >= 0 ? exponent : -exponent;
	n.sign = exponent >= 0 ? 0 : 1;
	load_format(&format_exponent, exponent);
	print_int_acc(&n, &format_exponent);
}

static void
	print_sign(int sign, const t_format *format)
{
	sign ? load_buffer('-') : 0;
	!sign && format->plus ? load_buffer('+') : 0;
}

void
	print_scientific_acc(double x, const t_format *format)
{
	t_print_params	params;
	int				sign;
	int				exponent;

	sign = x < 0.0 ? 1 : 0;
	x = x < 0.0 ? -x : x;
	exponent = first_digit_exponent(x);
	round_double(&x,
			(format->precision == -1 ? 6 : format->precision) - exponent);
	load_params(&params, format, x, sign);
	if (format->minus)
	{
		print_sign(sign, format);
		print_scientific_absolute_value(x, format);
		print_padding(format, params.len_padding);
	}
	else
	{
		if (format->padding != '0')
			print_padding(format, params.len_padding);
		print_sign(sign, format);
		if (format->padding == '0')
			print_padding(format, params.len_padding);
		print_scientific_absolute_value(x, format);
	}
}
