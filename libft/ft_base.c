/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:45:29 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/25 14:49:44 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the smallest length needed to store parameter n in a base of length l
*/

int			smallest_length(long long number, long long l)
{
	long long	power;
	int			result;

	power = l;
	result = 1;
	while (power <= number)
	{
		power = power * l;
		result++;
	}
	return (result);
}

/*
** Returns length of base and performs checks. Returns 0 if the base is invalid
*/

static int	check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (!base || !base[0] || !base[1])
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-'
			|| !('!' <= base[i] && base[i] <= '~'))
			return (0);
		i++;
	}
	return (i);
}

static void	ft_putnbr_base_fd_acc(long long n, char *alphabet, int l, int fd)
{
	if (n >= l)
	{
		ft_putnbr_base_fd_acc(n / l, alphabet, l, fd);
		ft_putnbr_base_fd_acc(n % l, alphabet, l, fd);
	}
	else
		ft_putchar_fd(alphabet[n], fd);
}

void		ft_putnbr_base_fd(long long n, char *alphabet, int fd)
{
	int	sign;
	int	l;

	l = check_base(alphabet);
	if (!(l = check_base(alphabet)))
		return ;
	sign = 0;
	if (n < 0)
		sign = 1;
	if (n == LLONG_MIN)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_base_fd_acc(-(n / l), alphabet, l, fd);
		ft_putnbr_base_fd_acc(-(n % l), alphabet, l, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_base_fd_acc(-n, alphabet, l, fd);
	}
	else
		ft_putnbr_base_fd_acc(n, alphabet, l, fd);
}
