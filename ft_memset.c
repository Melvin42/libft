/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:25:00 by melperri          #+#    #+#             */
/*   Updated: 2020/10/12 16:15:08 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*s, int	c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char	*)s)[i++] = (unsigned char)c;
	return (s);
}
