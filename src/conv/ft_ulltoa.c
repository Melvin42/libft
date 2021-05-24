/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:04:43 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:24:50 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_ulltoa(unsigned long long n)
{
	char				*s;
	u_int64_t			nb;
	int					len;

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
