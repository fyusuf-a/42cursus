/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 15:39:07 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/05/08 16:47:04 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_min(int x, int y)
{
	return (x < y ? x : y);
}

int		ft_max(int x, int y)
{
	return (x < y ? y : x);
}

int	ft_abs(int x)
{
	if (x >= 0)
		return (x);
	return (-x);
}
