/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:17:42 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/01 17:33:24 by lcalendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

void main_bzero()
{
	char dst[1];
	ft_bzero(NULL, 0);
	bzero(NULL, (0));
	//ft_bzero(NULL, 1);
	//bzero(NULL, (1));
	ft_bzero(dst, 0);
	bzero(dst, (0));
	//ft_bzero(dst, 10);
	//bzero(dst, (10));
}
