/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_nothing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:32:04 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/16 17:09:54 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_print_nothing(va_list *args)
{
	int	*n;

	n = va_arg(*args, int*);
	*n = ft_printf_get_g_return_value();
}
