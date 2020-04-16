/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_int2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:27:46 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/16 17:11:05 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void
	load_params(t_ft_printf_print_params *params,
			const t_ft_printf_format *format, t_ft_printf_integer *n,
			const t_ft_printf_base *base)
{
	int				len;

	params->len_proper = ft_printf_ilen(n->abs, base->length);
	if (format->precision == 0 && n->abs == 0)
		params->len_proper--;
	params->len_zeros = 0;
	if (format->precision != -1 && format->precision > params->len_proper)
		params->len_zeros = format->precision - params->len_proper;
	params->len_padding = 0;
	len = params->len_proper + params->len_zeros + n->sign;
	len += (format->plus && !n->sign ? 1 : 0);
	if (format->type == POINTER && format->width >= 2)
		len += 2;
	if (format->width != -1 && format->width > len)
		params->len_padding = format->width - len;
}

static void
	print_nbr(unsigned long long n, t_ft_printf_base *base,
			size_t i, size_t total)
{
	if (n >= base->length)
	{
		print_nbr(n / base->length, base, i, total);
		print_nbr(n % base->length, base, i + 1, total);
	}
	else if (i < total)
		ft_printf_load_buffer(base->str[n]);
}

static void
	print_int_acc_no_minus_helper(int sign, const t_ft_printf_format *format,
			const t_ft_printf_print_params *params)
{
	if (format->padding == '0')
	{
		sign ? ft_printf_load_buffer('-') : 0;
		!sign && format->plus ? ft_printf_load_buffer('+') : 0;
		format->type == POINTER ? ft_printf_print_zerox() : 0;
		ft_printf_print_padding(format, params->len_padding);
	}
	else
	{
		ft_printf_print_padding(format, params->len_padding);
		format->type == POINTER ? ft_printf_print_zerox() : 0;
		sign ? ft_printf_load_buffer('-') : 0;
		!sign && format->plus ? ft_printf_load_buffer('+') : 0;
	}
	ft_printf_print_zeros(params->len_zeros);
}

void
	ft_printf_print_int_acc(t_ft_printf_integer *n,
			const t_ft_printf_format *format)
{
	t_ft_printf_base			base;
	t_ft_printf_print_params	params;

	ft_printf_fill_base(&base, format);
	load_params(&params, format, n, &base);
	if (format->minus)
	{
		format->type == POINTER ? ft_printf_print_zerox() : 0;
		n->sign ? ft_printf_load_buffer('-') : 0;
		!n->sign && format->plus ? ft_printf_load_buffer('+') : 0;
		ft_printf_print_zeros(params.len_zeros);
		print_nbr(n->abs, &base, 0, params.len_proper);
		ft_printf_print_padding(format, params.len_padding);
	}
	else
	{
		print_int_acc_no_minus_helper(n->sign, format, &params);
		print_nbr(n->abs, &base, 0, params.len_proper);
	}
}
