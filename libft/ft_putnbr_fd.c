/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:45:29 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/10 16:37:40 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_acc(int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_fd_acc(n / 10, fd);
		ft_putnbr_fd_acc(n % 10, fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd_acc(-n, fd);
	}
	else
		ft_putnbr_fd_acc(n, fd);
}
