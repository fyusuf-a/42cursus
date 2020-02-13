/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:04:11 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/24 18:40:46 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define SIZE 30000

char	*g_prg_name;

void	put_str(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	print_error(char *error)
{
	put_str(basename(g_prg_name), 2);
	put_str(": ", 2);
	put_str(error, 2);
	put_str(": ", 2);
	put_str(strerror(errno), 2);
	put_str("\n", 2);
}

void print_struct(t_parse_state *st)
{
	printf("buffer:");
	for (int i = 0; i < st->char_nb; i++) 
		printf("%c", st->buffer[i]);
	printf("\ncursor:%d\n", st->cursor);
	printf("char_nb:%d\n", st->char_nb);
	if (st->flag == READ_FILE)
		printf("READ_FILE\n");
	else
		printf("READ_BUF\n");
}

int	main(int argc, char *argv[])
{
	char	*toto;
	int		gnl_result;
	int		fd;
	int		first_time = 1;
	
	(void)argc;
	(void)argv;
	/*if (argc != 2)*/
		/*printf("There should be exactly 2 arguments\n");*/
	g_prg_name = argv[0];
	/*fd = open(argv[1], O_RDONLY);*/
	fd = open("./test/file", O_RDONLY);
	while ((gnl_result = get_next_line(fd, &toto)) > 0)
	{
		if (!first_time)
			printf("\n");
		else
			first_time = 0;
		printf("%s", toto);
		free(toto);
	}
	if (gnl_result == 0)
		printf("\n%s", toto);
	if (gnl_result == -1)
		print_error("error while reading file");
}
