/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:14:27 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/24 13:37:53 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_ft_printf_buff g_buffer;
int g_ft_printf_return_value = 0;

int
	ft_printf_get_g_return_value(void)
{
	return (g_ft_printf_return_value);
}

void
	ft_printf_load_buffer(char c)
{
	if (g_buffer.cursor == BUFFER_SIZE)
	{
		g_buffer.cursor = 0;
		write(1, g_buffer.buffer, BUFFER_SIZE);
		g_ft_printf_return_value += BUFFER_SIZE;
	}
	g_buffer.buffer[g_buffer.cursor] = c;
	g_buffer.cursor++;
}

void
	ft_printf_flush_buffer(int fd)
{
	write(fd, g_buffer.buffer, g_buffer.cursor);
	g_ft_printf_return_value += g_buffer.cursor;
	g_buffer.cursor = 0;
}

int
	ft_zprintf(int fd, const char *str, va_list *list)
{
	t_ft_printf_format_str	st;
	t_ft_printf_format		format;

	st.buffer = str;
	st.cursor = 0;
	g_ft_printf_return_value = 0;
	g_buffer.cursor = 0;
	while (1)
	{
		ft_printf_initialize_format(&format);
		if (ft_printf_flush_format(&st) == -1)
			break ;
		if (ft_printf_parse_format(&format, list, &st) == -1)
			break ;
		ft_printf_print_arg(list, &format, &st);
	}
	ft_printf_flush_buffer(fd);
	return (g_ft_printf_return_value);
}
