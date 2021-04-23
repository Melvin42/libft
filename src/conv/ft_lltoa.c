/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:00:18 by melperri          #+#    #+#             */
/*   Updated: 2021/01/26 14:08:29 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_lltoa(long long n)
{
	char		*s;
	int64_t		nb;
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
