/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:19:55 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/22 20:25:38 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int
	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
** Goes to no more than index=n (excluded)
*/

static char
	*update(char **line, t_parse_state *st, size_t n)
{
	char	*ret;
	int		i;
	int		l;
	int		to_add;

	l = ft_strlen(*line);
	to_add = n - st->cursor;
	if (!(ret = malloc(l + to_add + 1)))
		return (NULL);
	i = 0;
	while (i < l)
	{
		ret[i] = (*line)[i];
		i++;
	}
	free(*line);
	while (i < l + to_add)
	{
		ret[i] = (st->buffer)[st->cursor];
		i++;
		st->cursor++;
	}
	ret[i] = '\0';
	return (ret);
}

/*
** -1 if not found, index i is returned if occurence is found after
** cursor (included)
*/

static int
	occurence(char c, t_parse_state *st)
{
	int	i;

	i = st->cursor;
	while (i < st->char_nb)
	{
		if (st->buffer[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int
	ft_gnl_read_buffer(int fd, char **line, t_parse_state *st)
{
	int		j;

	st->flag = READ_BUF;
	if (st->cursor < st->char_nb && (j = occurence('\n', st)) != -1)
	{
		if (!(*line = update(line, st, j)))
			return (RET_ERROR);
		st->cursor++;
		return (RET_FILE_READ);
	}
	else
	{
		if (st->cursor < st->char_nb)
			if (!(*line = update(line, st, st->char_nb)))
				return (RET_ERROR);
		return (ft_gnl_read_file(fd, line, st));
	}
	return (RET_ERROR);
}

int
	ft_gnl_read_file(int fd, char **line, t_parse_state *st)
{
	st->flag = READ_FILE;
	st->cursor = 0;
	if ((st->char_nb = read(fd, st->buffer, BUFFER_SIZE)) > 0)
		return (ft_gnl_read_buffer(fd, line, st));
	else if (st->char_nb == 0)
		return (RET_FILE_END);
	else
		return (RET_ERROR);
}
