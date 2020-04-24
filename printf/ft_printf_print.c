/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:24:26 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/24 13:23:24 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	ft_printf_print_padding(const t_ft_printf_format *format, int times)
{
	int i;

	i = 0;
	while (i++ < times)
		ft_printf_load_buffer(format->padding);
}

void
	ft_printf_print_arg(va_list *args, t_ft_printf_format *format,
			t_ft_printf_format_str *str)
{
	if (format->type == CHAR || format->type == PERCENTAGE
			|| format->type == UNKNOWN_TYPE)
		ft_printf_print_char(args, format, str);
	else if (format->type == STRING)
		ft_printf_print_str(args, format);
	else if (format->type == NOTHING)
		ft_printf_print_nothing(args);
	else if (format->type == DOUBLE || format->type == SCIENTIFIC
													|| format->type == G)
		ft_printf_print_double(args, format);
	else
		ft_printf_print_int(args, format);
}
