/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:24:14 by melperri          #+#    #+#             */
/*   Updated: 2020/10/12 18:33:45 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (((const unsigned char *)src)[i] != (unsigned char)c))
	{
		((unsigned char *)dest)[0] = ((const unsigned char *)src)[i];
		i++;
		dest++;
	}
	if ((((const unsigned char *)src)[i] == (unsigned char)c))
	{
		((unsigned char *)dest)[0] = ((const unsigned char *)src)[i];
		dest++;
	}
	else
		return (NULL);
	return (dest);
}
