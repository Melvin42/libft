/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:59:11 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:23:54 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*filltab(char *dest, int len, unsigned long long nb, char *base)
{
	unsigned long long	baselen;

	baselen = (unsigned long long)ft_strlen(base);
	dest[len] = '\0';
	while (--len >= 0)
	{
		dest[len] = base[nb % baselen];
		nb = nb / baselen;
	}
	return (dest);
}

static int	ulltoalen(unsigned long long nb, char *base)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / (unsigned long long)ft_strlen(base);
		len++;
	}
	return (len);
}

char	*ft_ulltoa_base(unsigned long long nb, char *base)
{
	int		len;
	char	*dest;

	len = ulltoalen(nb, base);
	if (nb == 0)
		len = 1;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	dest = filltab(dest, len, nb, base);
	return (dest);
}
