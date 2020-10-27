/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:23:13 by melperri          #+#    #+#             */
/*   Updated: 2020/10/12 19:06:15 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memmove function copies n bytes from memory area src to memory area 
** dest. The memory areas may overlap: copying takes place as though the bytes
** in src are first copied into a temporary array that does not overlap src or 
** dest, and the bytes are then copied from the temporary array to dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	tmp[n];

	if (n == 0 || dest == src)
		return (dest);
	ft_memcpy(tmp, src, n);
	ft_memcpy(dest, tmp, n);
	return (dest);
}
