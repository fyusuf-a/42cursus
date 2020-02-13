/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:53:29 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/07 17:07:12 by lcalendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void main_strlcpy()
{	
	char dst1[10];
	char dst2[10];
	char dst3[1] = "";
	char dst4[1000];

	printf("ft_strlcpy->%zu\n", ft_strlcpy(NULL, "Papapapap", 0));
	printf("   strlcpy->%zu\n", strlcpy(NULL, "Papapapap", 0));
	printf("ft_strlcpy->%zu\n", ft_strlcpy(dst4, "wait", 1000));
	printf("   strlcpy->%zu\n", strlcpy(dst4, "wait", 1000));
	printf("ft_strlcpy->%zu\n", ft_strlcpy(dst1, "", 10));
	printf("   strlcpy->%zu\n", strlcpy(dst1, "", 10));
	printf("ft_strlcpy->%zu\n", ft_strlcpy(NULL, "wait", 0));
	printf("   strlcpy->%zu\n", strlcpy(NULL, "wait", 0));
	printf("ft_strlcpy->%zu\n", ft_strlcpy(dst3, "wait", 1));
	printf("   strlcpy->%zu\n", strlcpy(dst3, "wait", 1));
	//ft_strlcpy(dst3, "wait I may be usefull for you in the next fifty-five years !", 35);
	//strlcpy(dst3, "wait I may be usefull for you in the next fifty-five years !", 35);

	//Segfault
	//strlcpy("Papapap", NULL, 0);
	//strlcpy(NULL, "Papapapap", 1);
	//strlcpy(NULL, NULL, 0);
	//strlcpy(NULL, "wait", 10);
	//strlcpy(dst2, NULL, 0);
	//strlcpy("Papapapa", NULL, 5);

	(void)dst1;
	(void)dst2;
	(void)dst3;
	(void)dst4;
}
