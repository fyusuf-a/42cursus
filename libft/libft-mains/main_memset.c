/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:15:04 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/01 17:55:45 by lcalendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void main_memset()
{
	char dst1[1000] = {0};
	char dst2[1000] = {0};

	printf("ft_memset->%s\n", ft_memset(NULL, 'j', 0));
	printf("   memset->%s\n", memset(NULL, 'j', (0)));
	//ft_memset(NULL, 'j', 1);
	//memset(NULL, 'j', 1);
	printf("ft_memset->%s\n", ft_memset(dst1, 'j', 0));
	printf("   memset->%s\n", memset(dst2, 'j', (0)));
	printf("ft_memset->%s\n", ft_memset(dst1, 'j', 2));
	printf("   memset->%s\n", memset(dst2, 'j', 2));
	printf("ft_memset->%s\n", ft_memset(dst1, '\0', 1000));
	printf("   memset->%s\n", memset(dst2, '\0', 1000));
}
