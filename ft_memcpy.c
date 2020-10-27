/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:24:40 by melperri          #+#    #+#             */
/*   Updated: 2020/10/12 22:24:06 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memcpy() function copies n bytes from memory area src to memory area
** dest. The memory areas must not overlap. 
** Use ft_memmove() if the memory areas do overlap.
*/

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	if (n == 0 || dest == src)
		return (dest);
	while (n--)
		((unsigned char	*)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}
