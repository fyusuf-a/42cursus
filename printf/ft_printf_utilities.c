/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:56:08 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/24 13:30:51 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_printf_atoi_strict(const char *str)
{
	int number;
	int done_something;

	done_something = 0;
	number = 0;
	while ('0' <= *str && *str <= '9')
	{
		done_something = 1;
		number = 10 * number + (*str - '0');
		str++;
	}
	if (done_something)
		return (number);
	else
		return (-1);
}

void
	ft_printf_advance_cursor(t_ft_printf_format_str *str, int n)
{
	int i;

	i = 0;
	while (i++ < n)
		str->cursor++;
}

/*
** Computes the total length of a positive number
*/

size_t
	ft_printf_ilen(long long unsigned number, long long unsigned l_base)
{
	size_t				result;

	result = 1;
	while (1)
	{
		number /= l_base;
		if (number == 0)
			return (result);
		result++;
	}
}

void
	ft_printf_print_zeros(size_t times)
{
	size_t i;

	i = 0;
	while (i++ < times)
		ft_printf_load_buffer('0');
}

void
	ft_printf_print_zerox(void)
{
	ft_printf_load_buffer('0');
	ft_printf_load_buffer('x');
}
