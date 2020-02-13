/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:19:17 by lcalendi          #+#    #+#             */
/*   Updated: 2019/11/12 14:53:42 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include <stdio.h>

int main()
{
	printf("\nAtoi\n");
	main_atoi();
	printf("\nBzero\n");
	main_bzero();
	printf("\nMemccpy\n");
	main_memccpy();
	printf("\nMemchr\n");
	main_memchr();
	printf("\nMemcmp\n");
	main_memcmp();
	printf("\nMemcpy\n");
	main_memcpy();
	printf("\nMemmove\n");
	main_memmove();
	printf("\nMemset\n");
	main_memset();
	printf("\nStrchr\n");
	main_strchr();
	printf("\nStrdup\n");
	main_strdup();
	printf("\nStrlcat\n");
	main_strlcat();
	printf("\nStrlcpy\n");
	main_strlcpy();
	printf("\nStrlen\n");
	main_strlen();
	printf("\nStrncmp\n");
	main_strncmp();
	printf("\nStrnstr\n");
	main_strnstr();
	printf("\nStrrchr\n");
	main_strrchr();
}
