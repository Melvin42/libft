/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:23:13 by melperri          #+#    #+#             */
/*   Updated: 2020/11/20 00:48:44 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** The ft_memmove function copies n bytes from memory area src to memory area
** dest. The memory areas may overlap: copying takes place as though the bytes
** in src are first copied into a temporary array that does not overlap src or
** dest, and the bytes are then copied from the temporary array to dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0 || dest == src)
		return (dest);
	if (dest > src)
		ft_memcpy_rev(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
