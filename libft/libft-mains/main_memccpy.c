/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:18:43 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/01 17:33:35 by lcalendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void main_memccpy()
{
	char dst[50] = "Je ne suis";
	char dst2[20] = "Lets get some color";
	char dst3[20] = "Lets get some color";
	char *str = "Decideriez jous de m'accorde quelqus minutes por favor ?";
	char *str2 = "por favor no";

	printf("ft_memccpy->%s\n", ft_memccpy(dst2, str, 'j', 20));
	printf("   memccpy->%s\n", memccpy(dst3, str, 'j', 20));
	printf("ft_memccpy->%s\n", ft_memccpy(dst2, str, 'j', 0));
	printf("   memccpy->%s\n", memccpy(dst3, str, 'j', 0));
	//ft_memccpy(dst2, NULL, 'j', 20);
	//memccpy(dst3, NULL, 'j', 20);
	printf("ft_memccpy->%s\n", ft_memccpy(dst2, NULL, 'j', 0));
	printf("   memccpy->%s\n", memccpy(dst3, NULL, 'j', 0));
	//ft_memccpy(NULL, str, 'j', 20);
	//memccpy(NULL, str, 'j', 20);
	printf("ft_memccpy->%s\n", ft_memccpy(NULL, str, 'j', 0));
	printf("   memccpy->%s\n", memccpy(NULL, str, 'j', 0));
	//ft_memccpy(NULL, NULL, 'j', 20);
	//memccpy(NULL, NULL, 'j', 20);
	printf("ft_memccpy->%s\n", ft_memccpy(NULL, NULL, 'j', 0));
	printf("   memccpy->%s\n", memccpy(NULL, NULL, 'j', 0));

	printf("ft_memccpy->%s\n", ft_memccpy(dst2, str, '\0', 20));
	printf("   memccpy->%s\n", memccpy(dst3, str, '\0', 20));
	printf("ft_memccpy->%s\n", ft_memccpy(dst2, str, '\0', 0));
	printf("   memccpy->%s\n", memccpy(dst3, str, '\0', 0));
	//ft_memccpy(dst2, NULL, '\0', 20);
	//memccpy(dst3, NULL, '\0', 20);
	printf("ft_memccpy->%s\n", ft_memccpy(dst2, NULL, '\0', 0));
	printf("   memccpy->%s\n", memccpy(dst3, NULL, '\0', 0));
	//ft_memccpy(NULL, str, '\0', 20);
	//memccpy(NULL, str, '\0', 20);
	printf("ft_memccpy->%s\n", ft_memccpy(NULL, str, '\0', 0));
	printf("   memccpy->%s\n", memccpy(NULL, str, '\0', 0));
	//ft_memccpy(NULL, NULL, '\0', 20);
	//memccpy(NULL, NULL, '\0', 20);
	printf("ft_memccpy->%s\n", ft_memccpy(NULL, NULL, '\0', 0));
	printf("   memccpy->%s\n", memccpy(NULL, NULL, '\0', 0));
	(void)dst;
	(void)dst2;
	(void)dst3;
	(void)str;
	(void)str2;
}
