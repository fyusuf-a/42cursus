/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:29:55 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/03 16:02:04 by lcalendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void main_memcmp()
{
	printf("ft_memcmp->%d\n", ft_memcmp(NULL, NULL, 0));
	printf("   memcmp->%d\n", memcmp(NULL, NULL, 0));
	//ft_memcmp(NULL, NULL, 1);
	//memcmp(NULL, NULL, 1);
	//ft_memcmp(NULL, "", 1);
	//memcmp(NULL, "", 1);
	//ft_memcmp("", NULL, 1);
	//memcmp("", NULL, 1);
	printf("ft_memcmp->%d\n", ft_memcmp("", "", 1000));
	printf("   memcmp->%d\n", memcmp("", "", 1000));
	//printf("ft_memcmp->%d\n", ft_memcmp("Am I very happy001", "Am I very happy001", -1));
	//printf("   memcmp->%d\n", memcmp("Am I very happy001", "Am I very happy001", -1));
	//ft_memcmp("Just not blank", "Just not blank", 100000);
	//memcmp("Just not blank", "Just not blank", 100000);
}
