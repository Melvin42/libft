/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:18:54 by melperri          #+#    #+#             */
/*   Updated: 2020/10/09 16:11:06 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		len;

	len = 0;
	nb = n;
	nb = (n < 0) ? nb * -1 : nb;
	len = (n < 0) ? 2 : 1;
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	if (!(s = malloc(sizeof(s) * len + 1)))
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
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(-9));
	printf("%s\n", ft_itoa(9));
	printf("%s\n", ft_itoa(0));
	return (0);
}
*/
