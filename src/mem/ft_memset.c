/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:25:00 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:47:10 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** The ft_memset() function fills the first n bytes of the memory area pointed
** to by s with the constant byte c.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	if (n == 0)
		return (s);
	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}
