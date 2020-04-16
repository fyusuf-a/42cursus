/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_atoi_strict.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:36:16 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/16 17:57:28 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi_strict(const char *str)
{
	int number;

	number = 0;
	while ('0' <= *str && *str <= '9')
	{
		number = 10 * number + (*str - '0');
		str++;
	}
	return (number);
}
