/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:36:16 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/13 14:02:49 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	int sign;
	int number;

	sign = 1;
	number = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		number = 10 * number + (*str - '0');
		str++;
	}
	return (sign * number);
}
