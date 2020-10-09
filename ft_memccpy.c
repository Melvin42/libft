/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:24:14 by melperri          #+#    #+#             */
/*   Updated: 2020/10/08 17:24:29 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void	*dest, const void	*src, int	c, unsigned int n)
{
	unsigned int i;

	unsigned char	*uc_dest;

	i = 0;
	uc_dest = (unsigned char	*)dest;
	while (uc_dest[i])
	{
		if (uc_dest[i] == (unsigned char)c)
			break;
		i++;
	}
	i = 0;
	while (i < n && (uc_dest[i] != (unsigned char)c))
	{
		uc_dest[i] = ((const unsigned char	*)src)[i];
		i++;
	}
	return (uc_dest);
}
