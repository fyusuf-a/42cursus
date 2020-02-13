/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:19:32 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/23 16:17:15 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_parse_state	st[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX - 1 || !line)
		return (-1);
	if (!(*line = malloc(1)))
		return (-1);
	(*line)[0] = '\0';
	if (st[fd].flag == READ_FILE)
		return (read_file(fd, line, &(st[fd])));
	else
		return (read_buffer(fd, line, &(st[fd])));
}
