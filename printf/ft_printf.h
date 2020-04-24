/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:04:08 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/24 13:38:35 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

typedef enum	e_ft_printf_type
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
}				t_ft_printf_type;

typedef enum	e_ft_printf_modifier
{
	NO_MODIFIER,
	LONG,
	LONG_LONG
}				t_ft_printf_modifier;

typedef struct	s_ft_printf_format {
	int						minus;
	int						plus;
	int						sharp;
	char					padding;
	int						width;
	int						precision;
	t_ft_printf_modifier	modifier;
	t_ft_printf_type		type;
}				t_ft_printf_format;

typedef struct	s_ft_printf_print_params {
	int		len_proper;
	int		len_padding;
	int		len_zeros;
}				t_ft_printf_print_params;

typedef struct	s_ft_printf_buff {
	char		buffer[BUFFER_SIZE];
	size_t		cursor;
}				t_ft_printf_buff;

typedef struct	s_ft_printf_format_str {
	const char	*buffer;
	size_t		cursor;
}				t_ft_printf_format_str;

typedef struct	s_ft_printf_base {
	char	*str;
	size_t	length;
}				t_ft_printf_base;

typedef struct	s_ft_printf_integer {
	int					sign;
	long long unsigned	abs;
}				t_ft_printf_integer;

/*
** ft_printf_format.c
*/

int				ft_printf_flush_format(t_ft_printf_format_str *str);
void			ft_printf_initialize_format(t_ft_printf_format *format);

/*
** ft_printf_main.c
*/

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

/*
** ft_printf_main2.c
*/

int				ft_printf_get_g_return_value(void);
void			ft_printf_load_buffer(char c);
void			ft_printf_flush_buffer();
int				ft_zprintf(int fd, const char *format, va_list *args);

/*
** ft_printf_parse_format.c
*/

int				ft_printf_parse_format(t_ft_printf_format *format,
	va_list *list, t_ft_printf_format_str *str);

/*
** ft_printf_parse_format2.c
*/

void			ft_printf_parse_modifier(t_ft_printf_format *format,
		t_ft_printf_format_str *st);
void			ft_printf_parse_type(t_ft_printf_format *format,
		t_ft_printf_format_str *st);

/*
** ft_printf_print.c
*/

void			ft_printf_print_padding(const t_ft_printf_format *format,
		int times);
void			ft_printf_print_arg(va_list *args,
		t_ft_printf_format *format, t_ft_printf_format_str *str);

/*
** ft_printf_print_str.c
*/

void			ft_printf_print_char(va_list *args,
		t_ft_printf_format *format, t_ft_printf_format_str *str);
void			ft_printf_print_str_acc(char *str,
		const t_ft_printf_format *format);
void			ft_printf_print_str(va_list *args, t_ft_printf_format *format);

/*
** ft_printf_print_int.c
*/

void			ft_printf_print_int(va_list *args, t_ft_printf_format *format);

/*
** ft_printf_print_int2.c
*/

void			ft_printf_print_int_acc(t_ft_printf_integer *n,
		const t_ft_printf_format *format);

/*
** ft_printf_print_nothing.c
*/

void			ft_printf_print_nothing(va_list *args);

/*
** ft_printf_utilities.c
*/

int				ft_printf_atoi_strict(const char *str);
void			ft_printf_advance_cursor(t_ft_printf_format_str *str, int n);
size_t			ft_printf_ilen(long long unsigned number,
		long long unsigned l_base);
void			ft_printf_print_zeros(size_t times);
void			ft_printf_print_zerox(void);

/*
**	ft_printf_utilities2.c
*/
void			ft_printf_fill_base(t_ft_printf_base *base,
		const t_ft_printf_format *format);

/*
**	ft_printf_print_double.c
*/

void			ft_printf_print_double(va_list *args,
		t_ft_printf_format *format);
void			ft_printf_print_double_acc(double x,
		const t_ft_printf_format *format);

/*
**  ft_printf_print_double2.c
*/

double			ft_printf_power(double x, int exp);
int				ft_printf_first_digit_exponent(double x);
void			ft_printf_print_decimal_part(double x, int precision);
void			ft_printf_print_integer_part(unsigned long long n);
void			ft_printf_round_double(double *x, int precision);

/*
**  ft_printf_print_scientific.c
*/

void			ft_printf_print_scientific_acc(double x,
		const t_ft_printf_format *format);

/*
**  ft_printf_print_g.c
*/

void			ft_printf_print_g(double x, const t_ft_printf_format *format);
void			ft_printf_print_g_acc(double x,
		const t_ft_printf_format *format);

#endif
