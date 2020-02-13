/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:25:41 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/01 17:34:43 by lcalendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

void main_strchr()
{
	//ft_strchr(NULL, 'l');
	//strchr(NULL, 'l');
	printf("ft_strchr->%s\n", ft_strchr("", 'l'));
	printf("   strchr->%s\n", strchr("", 'l'));
	printf("ft_strchr->%s\n", ft_strchr("Are you somewhere about there", 'l'));
	printf("   strchr->%s\n", strchr("Are you somewhere about there", 'l'));
	printf("ft_strchr->%s\n", ft_strchr("                             ", ' '));
	printf("   strchr->%s\n", strchr("                             ", ' '));
	printf("ft_strchr->%s\n", ft_strchr("", '\0'));
	printf("   strchr->%s\n", strchr("", '\0'));
	printf("ft_strchr->%s\n", ft_strchr("\0cutness", '\0'));
	printf("   strchr->%s\n", strchr("\0cutness", '\0'));
}
