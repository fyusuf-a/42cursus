/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:18:43 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/03 16:08:52 by lcalendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void main_memcpy()
{
	char dst[50] = "Je ne suis";
	char dst1[20] = {0};
	char dst2[20] = {0};
	char dst3[20] = {0};
	char dst4[20] = {0};
	char dst5[20] = {0};
	char dst6[20] = {0};
	char *str = "Decideriez vous de m'accorde quelqus minutes por favor ?";
	char *str2 = "por favor no";

	//printf("ft_memcpy->%s\n", ft_memcpy(dst2, str, 20));
	//printf("   memcpy->%s\n", memcpy(dst2, str, 20));
	printf("ft_memcpy->%s\n", ft_memcpy(dst3, str, 0));
	printf("   memcpy->%s\n", memcpy(dst4, str, 0));
	//ft_memcpy(dst2, NULL, 20);
	//memcpy(dst3, NULL, 20);
	printf("ft_memcpy->%s\n", ft_memcpy(dst5, NULL, 0));
	printf("   memcpy->%s\n", memcpy(dst6, NULL, 0));
	//ft_memcpy(NULL, str, 20);
	//memcpy(NULL, str, 20);
	printf("ft_memcpy->%s\n", ft_memcpy(NULL, str, 0));
	printf("   memcpy->%s\n", memcpy(NULL, str, 0));
	printf("ft_memcpy->%s\n", ft_memcpy(NULL, NULL, 20));
	printf("   memcpy->%s\n", memcpy(NULL, NULL, 20));
	printf("ft_memcpy->%s\n", ft_memcpy(NULL, NULL, 0));
	printf("   memcpy->%s\n", memcpy(NULL, NULL, 0));
	(void)dst;
	(void)dst1;
	(void)dst2;
	(void)str;
	(void)str2;
}
