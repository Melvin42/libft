/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:55:55 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:29:29 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*filltab(char *dest, int len, unsigned long nb, char *base)
{
	unsigned long	baselen;

	baselen = (unsigned long)ft_strlen(base);
	dest[len] = '\0';
	while (--len >= 0)
	{
		dest[len] = base[nb % baselen];
		nb = nb / baselen;
	}
	return (dest);
}

static int	ultoalen(unsigned long nb, char *base)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / (unsigned long)ft_strlen(base);
		len++;
	}
	return (len);
}

char	*ft_ultoa_base(unsigned long nb, char *base)
{
	int		len;
	char	*dest;

	len = ultoalen(nb, base);
	if (nb == 0)
		len = 1;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	dest = filltab(dest, len, nb, base);
	return (dest);
}
