/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:17:43 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/16 17:10:21 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long
	get_int_from_arg(va_list *args, const t_ft_printf_format *format)
{
	if (format->modifier == LONG_LONG)
		return ((long long)va_arg(*args, long long));
	if (format->modifier == LONG)
		return ((long long)va_arg(*args, long));
	else
		return ((long long)va_arg(*args, int));
}

static long long unsigned
	get_unsigned_int_from_arg(va_list *args, const t_ft_printf_format *format)
{
	if (format->modifier == LONG_LONG)
		return (va_arg(*args, long long unsigned int));
	if (format->modifier == LONG)
		return (va_arg(*args, long unsigned int));
	else
		return (va_arg(*args, unsigned int));
}

void
	ft_printf_print_int(va_list *args, t_ft_printf_format *format)
{
	t_ft_printf_integer	n;
	long long			temp;

	n.sign = 0;
	if (format->type == INT)
	{
		temp = get_int_from_arg(args, format);
		n.sign = temp < 0 ? 1 : 0;
		n.abs = temp >= 0 ? temp : -temp;
	}
	else if (format->type == POINTER)
		n.abs = (long long unsigned)va_arg(*args, unsigned long);
	else
		n.abs = get_unsigned_int_from_arg(args, format);
	ft_printf_print_int_acc(&n, format);
}
