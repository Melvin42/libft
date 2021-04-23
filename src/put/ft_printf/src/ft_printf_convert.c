/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:36:28 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 11:41:49 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_print_c(va_list ap, t_flags *flags)
{
	unsigned char	c;
	int				i;

	c = va_arg(ap, unsigned int);
	i = -1;
	if (!flags->width)
		flags->ret += write(1, &c, 1);
	else
	{
		if (!flags->moins)
		{
			while (++i < flags->width - 1)
				flags->ret += write(1, " ", 1);
			flags->ret += write(1, &c, 1);
		}
		else
		{
			flags->ret += write(1, &c, 1);
			while (++i < flags->width - 1)
				flags->ret += write(1, " ", 1);
		}
	}
}

void	ft_print_null_s(char *s, t_flags *flags)
{
	s = ft_strdup("(null)");
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
		ft_flags_string(flags, s);
	else
		flags->ret += write(1, s, flags->len);
	free(s);
	s = NULL;
}

void	ft_print_s(va_list ap, t_flags *flags)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
	{
		ft_print_null_s(s, flags);
		return ;
	}
	flags->len = (int)ft_strlen(s);
	if (is_flag_on(flags))
		ft_flags_string(flags, s);
	else
		flags->ret += write(1, s, flags->len);
}

void	ft_print_p(va_list ap, t_flags *flags)
{
	void	*p;
	char	*s;

	p = va_arg(ap, void *);
	if (p == NULL)
		null_addr(flags);
	else
	{
		s = ft_ultoa_base((unsigned long)p, BASEHEXMIN);
		flags->len = (int)ft_strlen(s);
		if (is_flag_on(flags))
			ft_flags_addr(flags, s);
		else
		{
			flags->ret += write(1, "0x", 2);
			flags->ret += write(1, s, flags->len);
		}
		free(s);
		s = NULL;
	}
}

void	ft_print_percent(t_flags *flags)
{
	int	i;

	i = -1;
	if (!flags->width)
		flags->ret += write(1, "%", 1);
	else
	{
		if (!flags->moins)
		{
			if (!flags->zero)
				while (++i < flags->width - 1)
					flags->ret += write(1, " ", 1);
			else
				while (++i < flags->width - 1)
					flags->ret += write(1, "0", 1);
			flags->ret += write(1, "%", 1);
			return ;
		}
		flags->ret += write(1, "%", 1);
		while (++i < flags->width - 1)
			flags->ret += write(1, " ", 1);
	}
}
