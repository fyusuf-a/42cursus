/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:47:38 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/12 12:59:51 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void main_strnstr()
{
	printf("ft_strnstr->%s\n", ft_strnstr("trucbizarre", "lil", 80000));
	printf("   strnstr->%s\n", strnstr("trucbizarre", "lil", 80000));
	printf("ft_strnstr->%s\n", ft_strnstr(NULL, "lil", 0));
	printf("   strnstr->%s\n", strnstr(NULL, "lil", 0));
	printf("ft_strnstr->%s\n", ft_strnstr("test", "", 4));
	printf("   strnstr->%s\n", strnstr("test", "", 4));
	printf("ft_strnstr->%s\n", ft_strnstr("", "", 4));
	printf("   strnstr->%s\n", strnstr("", "", 4));
	printf("ft_strnstr->%s\n", ft_strnstr("lorem ipsum dolor sit amet", "", 0));
	printf("   strnstr->%s\n", strnstr("lorem ipsum dolor sit amet", "", 0));
	printf("ft_strnstr->%s\n", ft_strnstr("", "Johnny is tired of having segfault from \"somewhere\"", 57));
	printf("   strnstr->%s\n", strnstr("", "Johnny is tired of having segfault from \"somewhere\"", 50));
	printf("ft_strnstr->%s\n", ft_strnstr("babababe", "bababe", 8));
	printf("   strnstr->%s\n", strnstr("babababe", "bababe", 8));
	printf("ft_strnstr->%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 0));
	printf("   strnstr->%s\n", strnstr("lorem ipsum dolor sit amet", "dolor", 0));
}
