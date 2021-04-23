/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:58:20 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 17:00:07 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_ltoa(long n)
{
	char		*s;
	long long	nb;
	int			len;

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
