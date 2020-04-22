/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:20:06 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/22 15:26:42 by fyusuf-a         ###   ########.fr       */
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

# define RET_ERROR     -1
# define RET_FILE_END  0
# define RET_FILE_READ 1

# ifndef OPEN_MAX
#  define OPEN_MAX FOPEN_MAX
# endif

typedef struct	s_parse_state {
	char	buffer[BUFFER_SIZE];
	int		cursor;
	int		char_nb;
	int		flag;
}				t_parse_state;

int				get_next_line(int fd, char **line);
int				ft_gnl_read_file(int fd, char **line, t_parse_state *st);
int				ft_gnl_read_buffer(int fd, char **line, t_parse_state *st);

#endif
