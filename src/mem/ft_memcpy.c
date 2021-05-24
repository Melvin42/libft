/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:24:40 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:47:36 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** The ft_memcpy() function copies n bytes from memory area src to memory area
** dest. The memory areas must not overlap.
** Use ft_memmove() if the memory areas do overlap.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (n == 0 || dest == src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
