/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:15:06 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:28:24 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*filltab(char *dest, int len, unsigned int nb, char *base)
{
	unsigned int	baselen;

	baselen = (unsigned int)ft_strlen(base);
	dest[len] = '\0';
	while (--len >= 0)
	{
		dest[len] = base[nb % baselen];
		nb = nb / baselen;
	}
	return (dest);
}

static int	utoalen(unsigned int nb, char *base)
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

char	*ft_utoa_base(unsigned int nb, char *base)
{
	int		len;
	char	*dest;

	len = utoalen(nb, base);
	if (nb == 0)
		len = 1;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	dest = filltab(dest, len, nb, base);
	return (dest);
}
