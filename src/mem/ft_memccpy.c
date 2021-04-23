/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:24:14 by melperri          #+#    #+#             */
/*   Updated: 2020/11/18 21:25:18 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** The ft_memccpy() function copies no more than n bytes from memory area src
** to memory area dest, stopping when the character c is found.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[0] = ((unsigned char *)src)[i];
		dest++;
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (dest);
		i++;
	}
	return (NULL);
}
