/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:04:08 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/16 14:05:02 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

typedef enum	e_type
{
	UNKNOWN_TYPE,
	NOTHING,
	CHAR,
	STRING,
	POINTER,
	INT,
	UNSIGNED_INT,
	HEXA_MIN,
	HEXA_MAJ,
	PERCENTAGE,
	DOUBLE,
	SCIENTIFIC,
	G
}				t_type;

typedef enum	e_modifier
{
	NO_MODIFIER,
	LONG,
	LONG_LONG
}				t_modifier;

typedef struct	s_format {
	int			minus;
	int			plus;
	int			sharp;
	char		padding;
	int			width;
	int			precision;
	t_modifier	modifier;
	t_type		type;
}				t_format;

typedef struct	s_print_params {
	int		len_proper;
	int		len_padding;
	int		len_zeros;
}				t_print_params;

typedef struct	s_buff {
	char	*buffer;
	size_t	cursor;
}				t_buff;

typedef struct	s_base {
	char	*str;
	size_t	length;
}				t_base;

typedef struct	s_integer {
	int					sign;
	long long unsigned	abs;
}				t_integer;

/*
** format.c
*/

int				flush_format(t_buff *str);
void			initialize_format(t_format *format);

/*
** ft_printf.c
*/

int				ft_printf(char *format, ...);
int				ft_dprintf(int fd, char *format, ...);

/*
** ft_printf2.c
*/

int				get_g_return_value(void);
void			load_buffer(char c);
void			flush_buffer();
int				ft_zprintf(int fd, char *format, va_list *args);

/*
** parse_format.c
*/

int				parse_format(t_format *format, va_list *list, t_buff *str);

/*
** parse_format2.c
*/

void			parse_modifier(t_format *format, t_buff *st);
void			parse_type(t_format *format, t_buff *st);

/*
** print.c
*/

void			print_padding(const t_format *format, int times);
void			print_arg(va_list *args, t_format *format, t_buff *str);

/*
** print_str.c
*/

void			print_char(va_list *args, t_format *format, t_buff *str);
void			print_str_acc(char *str, const t_format *format);
void			print_str(va_list *args, t_format *format);

/*
** print_int.c
*/

void			print_int(va_list *args, t_format *format);

/*
** print_int2.c
*/

void			print_int_acc(t_integer *n, const t_format *format);

/*
** print_nothing.c
*/

void			print_nothing(va_list *args);

/*
**				utilities.c
*/

int				ft_atoi_strict(const char *str);
void			advance_cursor(t_buff *str, int n);
size_t			ft_ilen(long long unsigned number, long long unsigned l_base);
void			print_zeros(size_t times);
void			print_zerox(void);

/*
**				utilities2.c
*/
void			fill_base(t_base *base, const t_format *format);

/*
**				print_double.c
*/

void			print_double(va_list *args, t_format *format);
void			print_double_acc(double x, const t_format *format);

/*
**				print_double2.c
*/

double			power(double x, int exp);
int				first_digit_exponent(double x);
void			print_decimal_part(double x, int precision);
void			print_integer_part(unsigned long long n);
void			round_double(double *x, int precision);

/*
**				print_scientific.c
*/

void			print_scientific_acc(double x, const t_format *format);

/*
**				print_g.c
*/

void			print_g(double x, const t_format *format);
void			print_g_acc(double x, const t_format *format);

#endif
