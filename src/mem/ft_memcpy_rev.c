/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 00:28:29 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:46:40 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** The ft_memcpy() function copies n bytes from memory area src to memory area
** dest. The memory areas must not overlap.
** Use ft_memmove() if the memory areas do overlap.
*/

void	*ft_memcpy_rev(void *dest, const void *src, size_t n)
{
	if (n == 0 || dest == src)
		return (dest);
	while (n--)
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}
