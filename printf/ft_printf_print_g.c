/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_g.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:31:16 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/16 17:13:24 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int
	number_of_decimals_double_acc(double x, int digits, int i)
{
	int	result;

	if (i >= digits)
		return (0);
	result = number_of_decimals_double_acc(10 * (x - (int)x), digits, i + 1);
	if ((int)x == 0 && result == 0)
		return (0);
	else
		return (1 + result);
}

static int
	number_of_decimals_double(double x, int digits)
{
	return (number_of_decimals_double_acc(x, digits, 0));
}

static void
	round_g(int *max_power, int *min_power, double *x,
			const t_ft_printf_format *format)
{
	double		abs_value;
	double		y;
	int			digit_number;
	int			round_to;

	abs_value = *x < 0 ? -*x : *x;
	*max_power = ft_printf_first_digit_exponent(abs_value);
	digit_number = format->precision == -1 ? 6 : format->precision;
	round_to = *max_power - digit_number + 1;
	round_to = round_to < 0 ? -round_to : round_to;
	ft_printf_round_double(&abs_value, round_to);
	*x = *x < 0 ? -abs_value : abs_value;
	*max_power = ft_printf_first_digit_exponent(abs_value);
	y = abs_value * ft_printf_power(10, -*max_power);
	*min_power = *max_power - number_of_decimals_double(y, digit_number);
}

void
	ft_printf_print_g_acc(double x, const t_ft_printf_format *format)
{
	t_ft_printf_format	format_cpy;
	int					digit_number;
	int					max_power;
	int					min_power;

	format_cpy = *format;
	if (x == 0)
	{
		format_cpy.precision = 0;
		ft_printf_print_double_acc(x, &format_cpy);
		return ;
	}
	round_g(&max_power, &min_power, &x, format);
	digit_number = format->precision == -1 ? 6 : format->precision;
	if (max_power >= digit_number || min_power <= -4 - (digit_number - 1))
		ft_printf_print_scientific_acc(x, format);
	else
	{
		format_cpy.precision = min_power < 0 ? -min_power : 0;
		ft_printf_print_double_acc(x, &format_cpy);
	}
}
