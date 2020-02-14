/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:14:27 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/02/08 17:52:00 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_buff	g_buffer;
int				g_return_value = 0;

int
	get_g_return_value(void)
{
	return (g_return_value);
}

void
	load_buffer(char c)
{
	if (g_buffer.cursor == BUFFER_SIZE)
	{
		g_buffer.cursor = 0;
		write(1, g_buffer.buffer, BUFFER_SIZE);
		g_return_value += BUFFER_SIZE;
	}
	g_buffer.buffer[g_buffer.cursor] = c;
	g_buffer.cursor++;
}

void
	flush_buffer(void)
{
	write(1, g_buffer.buffer, g_buffer.cursor);
	g_return_value += g_buffer.cursor;
	g_buffer.cursor = 0;
}

int
	ft_printf(char *str, ...)
{
	va_list			args;
	t_buff			st;
	t_format		format;

	if (!(g_buffer.buffer = malloc(BUFFER_SIZE)))
		return (0);
	st.buffer = str;
	st.cursor = 0;
	va_start(args, str);
	g_return_value = 0;
	g_buffer.cursor = 0;
	while (1)
	{
		initialize_format(&format);
		if (flush_format(&st) == -1)
			break ;
		if (parse_format(&format, &args, &st) == -1)
			break ;
		print_arg(&args, &format, &st);
	}
	flush_buffer();
	va_end(args);
	free(g_buffer.buffer);
	return (g_return_value);
}
