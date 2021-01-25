/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:18:54 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 13:45:08 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		len;

	nb = n;
	nb = (n < 0) ? nb * -1 : nb;
	len = (n < 0) ? 2 : 1;
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	if (!(s = malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len] = '\0';
	nb = n;
	nb = (n < 0) ? nb * -1 : nb;
	while (len - 1 >= 0)
	{
		s[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	s[0] = (n < 0) ? '-' : s[0];
	return (s);
}
