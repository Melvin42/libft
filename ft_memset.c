/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:25:00 by melperri          #+#    #+#             */
/*   Updated: 2020/10/08 17:25:07 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*s, int	c, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		((unsigned char	*)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
