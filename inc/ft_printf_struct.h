/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:09:27 by melperri          #+#    #+#             */
/*   Updated: 2021/01/27 20:06:35 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H

typedef struct	s_flags
{
	int				moins;
	int				zero;
	unsigned short	width;
	int				point;
	int				preci;
	int				star;
	int				len;
	int				ret;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				space;
	int				hash;
	int				plus;
}				t_flags;

#endif
