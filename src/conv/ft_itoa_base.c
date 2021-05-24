/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 08:29:32 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:25:53 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include <limits.h>

static char	*filltab(char *dest, int len, unsigned int nb, char *base)
{
	unsigned int	baselen;

	baselen = (unsigned int)ft_strlen(base);
	dest[len] = '\0';
	if (nb < 0)
	{
		dest[0] = '-';
		nb = nb * -1;
		while (--len > 0)
		{
			dest[len] = base[nb % baselen];
			nb = nb / baselen;
		}
	}
	else
	{
		while (--len >= 0)
		{
			dest[len] = base[nb % baselen];
			nb = nb / baselen;
		}
	}
	return (dest);
}

static int	itoalen(unsigned int nb, char *base)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / (unsigned int)ft_strlen(base);
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int n, char *base)
{
	int				sign;
	int				len;
	unsigned int	nb;
	char			*dest;

	sign = -1;
	if (n < 0)
	{
		n *= -1;
		nb = n;
		sign *= -1;
	}
	else
		nb = n;
	len = itoalen(nb, base);
	if (n <= 0)
		len = len + 1;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	dest = filltab(dest, len, nb, base);
	return (dest);
}
