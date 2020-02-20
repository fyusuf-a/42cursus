/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:14:27 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/02/20 13:53:25 by fyusuf-a         ###   ########.fr       */
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
	flush_buffer(int fd)
{
	write(fd, g_buffer.buffer, g_buffer.cursor);
	g_return_value += g_buffer.cursor;
	g_buffer.cursor = 0;
}

int
	ft_zprintf(int fd, char *str, va_list *list)
{
	t_buff			st;
	t_format		format;

	if (!(g_buffer.buffer = malloc(BUFFER_SIZE)))
		return (0);
	st.buffer = str;
	st.cursor = 0;
	g_return_value = 0;
	g_buffer.cursor = 0;
	while (1)
	{
		initialize_format(&format);
		if (flush_format(&st) == -1)
			break ;
		if (parse_format(&format, list, &st) == -1)
			break ;
		print_arg(list, &format, &st);
	}
	flush_buffer(fd);
	free(g_buffer.buffer);
	return (g_return_value);
}
