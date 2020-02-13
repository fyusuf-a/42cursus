/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:23:20 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/12 12:02:05 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void main_strlcat()
{
	char dst1[10] = {0};
	char dst2[10] = {0};
	char dst3[10] = {0};
	char dst4[10] = {0};
	char dst7[10] = {0};
	char dst8[10] = {0};
	char dst5[1];
	char dst6[1];

	printf("ft_strlcat->%zu\n", ft_strlcat(dst1, "wait", 10));
	printf("   strlcat->%zu\n", strlcat(dst2, "wait", 10));
	printf("ft_strlcat->%zu\n", ft_strlcat(dst3, "", 10));
	printf("   strlcat->%zu\n", strlcat(dst4, "", 10));
	//ft_strlcat(dst1, NULL, 10);
	//strlcat(dst2, NULL, 10);
	//ft_strlcat(NULL, "wait", 10);
	//strlcat(NULL, "wait", 10);
	//ft_strlcat(NULL, NULL, 0);
	//strlcat(NULL, NULL, 0);
	//ft_strlcat(NULL, NULL, 1);
	//strlcat(NULL, NULL, 1);
	//printf("ft_strlcat->%zu\n", ft_strlcat(dst7, NULL, 0));
	//printf("   strlcat->%zu\n", strlcat(dst8, NULL, 0));
	printf("ft_strlcat->%zu\n", ft_strlcat(NULL, "wait", 0));
	printf("   strlcat->%zu\n", strlcat(NULL, "wait", 0));
	printf("ft_strlcat->%zu\n", ft_strlcat(dst5, "wait", 1));
	printf("   strlcat->%zu\n", strlcat(dst6, "wait", 1));
	(void)dst7;
	(void)dst8;
}
