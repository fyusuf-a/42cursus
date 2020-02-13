/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:20:06 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/22 14:54:57 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

# define READ_FILE 0
# define READ_BUF 1

typedef struct	s_parse_state {
	char	buffer[BUFFER_SIZE];
	int		cursor;
	int		char_nb;
	int		flag;
}				t_parse_state;

int				get_next_line(int fd, char **line);
int				read_file(int fd, char **line, t_parse_state *st);
int				read_buffer(int fd, char **line, t_parse_state *st);

#endif
