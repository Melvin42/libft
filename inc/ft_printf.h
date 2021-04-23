/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:37:49 by melperri          #+#    #+#             */
/*   Updated: 2021/01/27 20:09:18 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define BASEHEXMIN "0123456789abcdef"
# define BASEHEXMAJ "0123456789ABCDEF"

# include "ft_printf_struct.h"
# include "../libft/libft.h"
# include <stdarg.h>

/*
******** PRINTF ********
*/

int		ft_printf(const char *full, ...);

/*
******** CONVERT *******
*/

void	ft_print_percent(t_flags *flags);
void	ft_print_c(va_list ap, t_flags *flags);
void	ft_print_s(va_list ap, t_flags *flags);
void	ft_print_p(va_list ap, t_flags *flags);
void	ft_print_int(va_list ap, t_flags *flags);
void	ft_print_u(va_list ap, t_flags *flags);
void	ft_print_hexmin(va_list ap, t_flags *flags);
void	ft_print_hexmaj(va_list ap, t_flags *flags);

/*
******** FLAG ********
*/

int		is_flag_on(t_flags *flags);
void	ft_flags_addr(t_flags *flags, char *s);
int		ft_flag_star_width(t_flags *flags, va_list ap);
int		ft_flag_star_preci(t_flags *flags, va_list ap);
void	fill_struct_part1(t_flags *flags, const char **full, va_list ap);
void	ft_flag_space(t_flags *flags, int d);

/*
******** STRING ********
*/

void	ft_flags_string(t_flags *flags, char *s);
void	no_flag_zero_string(t_flags *flags, char *s);

/*
******** ADDR ********
*/

void	ft_flags_addr(t_flags *flags, char *s);
void	null_addr(t_flags *flags);

/*
******** INT ********
*/

void	ft_flags_int(t_flags *flags, char *s);
void	ft_flags_int_neg(t_flags *flags, char *s);
void	ft_flags_int_plus(t_flags *flags, char *s);
void	ft_flags_hexmin(t_flags *flags, char *s);
void	ft_flags_hexmaj(t_flags *flags, char *s);

/*
******* BONUS *********
*/

int		is_modifier(t_flags *flags, char c);
int		is_modifier2(t_flags *flags, char c);
void	print_conv_modif(const char **full, t_flags *flags, va_list ap);
void	print_conv2_modif(const char **full, t_flags *flags, va_list ap);

void	ft_print_long(va_list ap, t_flags *flags);
void	ft_print_long_long(va_list ap, t_flags *flags);
void	ft_print_ul(va_list ap, t_flags *flags);
void	ft_print_ull(va_list ap, t_flags *flags);
void	ft_print_us(va_list ap, t_flags *flags);
void	ft_print_signed_char(va_list ap, t_flags *flags);
void	ft_print_hhu(va_list ap, t_flags *flags);

void	ft_print_hexmin_ul(va_list ap, t_flags *flags);
void	ft_print_hexmaj_ul(va_list ap, t_flags *flags);
void	ft_print_hexmin_ull(va_list ap, t_flags *flags);
void	ft_print_hexmaj_ull(va_list ap, t_flags *flags);
void	ft_print_hexmin_us(va_list ap, t_flags *flags);
void	ft_print_hexmaj_us(va_list ap, t_flags *flags);
void	ft_print_hexmin_hh(va_list ap, t_flags *flags);
void	ft_print_hexmaj_hh(va_list ap, t_flags *flags);
int		is_bonus_flags(t_flags *flags, char c);
void	ft_nopreci_hexmaj2(t_flags *flags, char *s, int i);
void	ft_nopreci_hexmin2(t_flags *flags, char *s, int i);

#endif
