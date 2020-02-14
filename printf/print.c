/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:24:26 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/02/08 16:50:30 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	print_padding(const t_format *format, int times)
{
	int i;

	i = 0;
	while (i++ < times)
		load_buffer(format->padding);
}

void
	print_arg(va_list *args, t_format *format, t_buff *str)
{
	if (format->type == CHAR || format->type == PERCENTAGE
			|| format->type == UNKNOWN_TYPE)
		print_char(args, format, str);
	else if (format->type == STRING)
		print_str(args, format);
	else if (format->type == NOTHING)
		print_nothing(args);
	else if (format->type == DOUBLE || format->type == SCIENTIFIC
													|| format->type == G)
		print_double(args, format);
	else
		print_int(args, format);
}
