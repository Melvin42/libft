/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:56:40 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 13:43:41 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	char			*s;
	unsigned int	nb;
	int				len;

	nb = n;
	len = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	if (!(s = malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len] = '\0';
	nb = n;
	while (len - 1 >= 0)
	{
		s[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (s);
}
