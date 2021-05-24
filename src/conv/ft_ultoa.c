/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:04:04 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:27:30 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_ultoa(unsigned long n)
{
	char			*s;
	unsigned long	nb;
	int				len;

	nb = n;
	len = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	s = malloc(sizeof(char) * len + 1);
	if (!s)
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
