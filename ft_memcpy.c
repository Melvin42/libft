/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:24:40 by melperri          #+#    #+#             */
/*   Updated: 2020/10/08 17:24:51 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, unsigned int n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	
	while (((unsigned char	*)dest)[i])
		i++;
	while (((unsigned const char	*)src)[j])
		j++;
	i = 0;
	while (i < n)
	{
		((unsigned char	*)dest)[i] = ((unsigned const char	*)src)[i];
		i++;
	}
	return (dest);
}
