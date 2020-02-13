/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:42:14 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/03 15:28:20 by lcalendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main_strrchr()
{
	char *str;
	size_t loop = 0;
	if (!(str = malloc(sizeof(char) * 3000000001)))
		return ;
	while (loop < 10)
		str[loop++] = 'j';
	while (loop < 2999999990)
		str[loop++] = 'o';
	while (loop < 3000000000)
		str[loop++] = 'o';
	str[loop] = 0;
	printf("ft_strrchr->%s\n", ft_strrchr("", 'l'));
	printf("   strrchr->%s\n", strrchr("", 'l'));
	//ft_strrchr(NULL, 'l');
	//strrchr(NULL, 'l');
	printf("ft_strrchr->%s\n", ft_strrchr("Just are you dead Joey ?", 'l'));
	printf("   strrchr->%s\n", strrchr("Just are you dead Joey", 'l'));
	printf("ft_strrchr->%s\n", ft_strrchr("                    ", ' '));
	printf("   strrchr->%s\n", strrchr("                    ", ' '));
	printf("ft_strrchr->%s\n", ft_strrchr("\0 Johnny", '\0'));
	printf("   strrchr->%s\n", strrchr("\0 Johnny", '\0'));
	//printf("ft_strrchr->%s\n", ft_strrchr(str, 'j'));
	//printf("   strrchr->%s\n", strrchr(str, 'j'));
	free(str);
}
