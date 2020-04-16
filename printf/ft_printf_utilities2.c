/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:52:46 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/16 17:06:08 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void
	ft_printf_fill_base(t_ft_printf_base *base,
			const t_ft_printf_format *format)
{
	if (format->type == HEXA_MIN || format->type == POINTER)
	{
		base->str = "0123456789abcdef";
		base->length = 16;
	}
	else if (format->type == HEXA_MAJ)
	{
		base->str = "0123456789ABCDEF";
		base->length = 16;
	}
	else
	{
		base->str = "0123456789";
		base->length = 10;
	}
}
