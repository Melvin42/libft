/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:33:06 by melperri          #+#    #+#             */
/*   Updated: 2021/01/27 19:34:39 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		is_modifier(t_flags *flags, char c)
{
	if (c == 'l')
	{
		flags->l = TRUE;
		return (TRUE);
	}
	else if (c == 'h')
	{
		flags->h = TRUE;
		return (TRUE);
	}
	else
		return (FALSE);
}

int		is_modifier2(t_flags *flags, char c)
{
	if (flags->l)
	{
		if (c == 'l')
		{
			flags->ll = TRUE;
			return (TRUE);
		}
	}
	else if (flags->h)
	{
		if (c == 'h')
		{
			flags->hh = TRUE;
			return (TRUE);
		}
	}
	return (FALSE);
}

void	print_conv_modif(const char **full, t_flags *flags, va_list ap)
{
	if (flags->ll || flags->hh)
		print_conv2_modif(full, flags, ap);
	else if (flags->l && !flags->ll && !flags->hh)
	{
		if (**full == 'd' || **full == 'i')
			ft_print_long(ap, flags);
		else if (**full == 'u')
			ft_print_ul(ap, flags);
		else if (**full == 'x')
			ft_print_hexmin_ul(ap, flags);
		else if (**full == 'X')
			ft_print_hexmaj_ul(ap, flags);
	}
	else if (flags->h && !flags->ll && !flags->hh)
	{
		if (**full == 'd' || **full == 'i')
			ft_print_int(ap, flags);
		else if (**full == 'u')
			ft_print_us(ap, flags);
		else if (**full == 'x')
			ft_print_hexmin_us(ap, flags);
		else if (**full == 'X')
			ft_print_hexmaj_us(ap, flags);
	}
}

void	print_conv2_modif(const char **full, t_flags *flags, va_list ap)
{
	if (flags->ll)
	{
		if (**full == 'd' || **full == 'i')
			ft_print_long_long(ap, flags);
		else if (**full == 'u')
			ft_print_ull(ap, flags);
		else if (**full == 'x')
			ft_print_hexmin_ull(ap, flags);
		else if (**full == 'X')
			ft_print_hexmaj_ull(ap, flags);
	}
	else if (flags->hh)
	{
		if (**full == 'd' || **full == 'i')
			ft_print_signed_char(ap, flags);
		else if (**full == 'u')
			ft_print_hhu(ap, flags);
		else if (**full == 'x')
			ft_print_hexmin_hh(ap, flags);
		else if (**full == 'X')
			ft_print_hexmaj_hh(ap, flags);
	}
}
