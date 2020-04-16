/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_double2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:04:43 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/16 17:15:29 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double
	ft_printf_power(double x, int exp)
{
	if (exp > 0)
		return (x * ft_printf_power(x, exp - 1));
	else if (exp < 0)
		return (1 / x * ft_printf_power(x, exp + 1));
	else
		return (1);
}

/*
** if x is positive and x = d * 10^k + ... where k is the highest exponent in
** the decomposition, returns the value of k
*/

int
	ft_printf_first_digit_exponent(double x)
{
	if ((1.0 <= x && x < 10.0) || x == 0.0)
		return (0);
	else if (0.0 < x && x < 1.0)
		return (-1 + ft_printf_first_digit_exponent(x * 10.0));
	else
		return (1 + ft_printf_first_digit_exponent(x / 10.0));
}

void
	ft_printf_print_decimal_part(double x, int precision)
{
	char digit;

	if (precision > 0)
	{
		digit = (int)x;
		ft_printf_load_buffer('0' + digit);
		ft_printf_print_decimal_part((x - digit) * 10, precision - 1);
	}
}

void
	ft_printf_print_integer_part(unsigned long long n)
{
	if (n >= 10)
	{
		ft_printf_print_integer_part(n / 10);
		ft_printf_print_integer_part(n % 10);
	}
	else
		ft_printf_load_buffer('0' + n);
}

void
	ft_printf_round_double(double *x, int precision)
{
	double y;

	y = *x * ft_printf_power(10, precision);
	y = 10 * (y - (int)y);
	if ((int)y >= 5)
		*x = *x + ft_printf_power(10, -precision);
}
