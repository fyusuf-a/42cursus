/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:18:43 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/12 14:57:29 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void main_memmove()
{
	char dst[50] = "Je ne suis";
	char dst4[50] = "Je ne suis";
	char dst2[20];
	char dst3[20];
	char *str = "Decideriez vous de m'accorde quelqus minutes por favor ?";
	char *str2 = "por favor no";

	//printf("ft_memmove->%s\n", ft_memmove(dst2, str, 20));
	//printf("   memmove->%s\n", memmove(dst3, str, 20));
	printf("ft_memmove->%s\n", ft_memmove(dst3, str, 0));
	printf("   memmove->%s\n", memmove(dst3, str, 0));
	//ft_memmove(dst2, NULL, 20);
	//memmove(dst3, NULL, 20);
	printf("ft_memmove->%s\n", ft_memmove(dst3, NULL, 0));
	printf("   memmove->%s\n", memmove(dst3, NULL, 0));
	//ft_memmove(NULL, str, 20);
	//memmove(NULL, str, 20);
	printf("ft_memmove->%s\n", ft_memmove(NULL, str, 0));
	printf("   memmove->%s\n", memmove(NULL, str, 0));
	printf("ft_memmove->%s\n", ft_memmove(NULL, NULL, 20));
	printf("   memmove->%s\n", memmove(NULL, NULL, 20));
	printf("ft_memmove->%s\n", ft_memmove(NULL, NULL, 0));
	printf("   memmove->%s\n", memmove(NULL, NULL, 0));
	printf("ft_memmove->%s\n", ft_memmove(dst, dst+10, 40));
	printf("   memmove->%s\n", memmove(dst4, dst4+10, 40));
	printf("ft_memmove->%s\n", ft_memmove(dst + 10, dst, 40));
	printf("   memmove->%s\n", memmove(dst4 + 10, dst4, 40));
	(void)dst;
	(void)dst2;
	(void)str;
	(void)str2;
}
