/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:23:28 by melperri          #+#    #+#             */
/*   Updated: 2020/10/12 12:08:08 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** Checks whether c is a 7-bit unsigned char value that fits into the ASCII
** character set.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
