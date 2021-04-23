/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:42:57 by melperri          #+#    #+#             */
/*   Updated: 2021/02/01 11:46:41 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	is_converter(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'u' || c == 'x'
			|| c == 'X' || c == '%')
		return (TRUE);
	else
		return (FALSE);
}

static void	print_conv(const char **full, t_flags *flags, va_list ap)
{
	if (**full == 'c')
		ft_print_c(ap, flags);
	else if (**full == 's')
		ft_print_s(ap, flags);
	else if (**full == 'p')
		ft_print_p(ap, flags);
	else if (**full == 'd' || **full == 'i')
		ft_print_int(ap, flags);
	else if (**full == 'u')
		ft_print_u(ap, flags);
	else if (**full == 'x')
		ft_print_hexmin(ap, flags);
	else if (**full == 'X')
		ft_print_hexmaj(ap, flags);
	else if (**full == '%')
		ft_print_percent(flags);
}

static void	init_struct(t_flags *flags)
{
	flags->moins = FALSE;
	flags->zero = FALSE;
	flags->width = FALSE;
	flags->point = FALSE;
	flags->preci = FALSE;
	flags->star = FALSE;
	flags->len = FALSE;
	flags->l = FALSE;
	flags->ll = FALSE;
	flags->h = FALSE;
	flags->hh = FALSE;
	flags->space = FALSE;
	flags->hash = FALSE;
	flags->plus = FALSE;
}

static void	pars_string(const char **full, t_flags *flags, va_list ap)
{
	while (**full)
	{
		if (**full == '%')
		{
			init_struct(flags);
			(*full)++;
			fill_struct_part1(flags, full, ap);
			break ;
		}
		flags->ret += write(1, *full, 1);
		(*full)++;
	}
	if (is_modifier(flags, **full))
		(*full)++;
	if (is_modifier2(flags, **full))
		(*full)++;
	if (is_converter(**full))
	{
		if (flags->l || flags->h)
			print_conv_modif(full, flags, ap);
		else
			print_conv(full, flags, ap);
		(*full)++;
	}
}

int			ft_printf(const char *full, ...)
{
	t_flags	flags;
	va_list	ap;

	va_start(ap, full);
	init_struct(&flags);
	flags.ret = FALSE;
	while (*full)
	{
		pars_string(&full, &flags, ap);
		if (flags.ret == -1)
			return (ERROR);
	}
	va_end(ap);
	return (flags.ret);
}
