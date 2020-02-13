/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:20:40 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/12 12:23:03 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void main_strncmp()
{
	printf("ft_strncmp->%d\n", ft_strncmp("test", "tr", 10000));
	printf("   strncmp->%d\n", strncmp("test", "tr", 10000));
	printf("ft_strncmp->%d\n", ft_strncmp("", "true fact", 4));
	printf("   strncmp->%d\n", strncmp("", "true fact", 4));
	printf("ft_strncmp->%d\n", ft_strncmp("test", "", 4));
	printf("   strncmp->%d\n", strncmp("test", "", 4));
	//ft_strncmp(NULL, "true fact", 4);
	//strncmp(NULL, "true fact", 4);
	printf("ft_strncmp->%d\n", ft_strncmp(NULL, "tr", 0));
	printf("   strncmp->%d\n", strncmp(NULL, "tr", 0));
	printf("ft_strncmp->%d\n", ft_strncmp("test", NULL, 0));
	printf("   strncmp->%d\n", strncmp("test", NULL, 0));
	printf("ft_strncmp->%d\n", ft_strncmp(NULL, NULL, 0));
	printf("   strncmp->%d\n", strncmp(NULL, NULL, 0));
}
