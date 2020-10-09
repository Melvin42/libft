/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:29:09 by melperri          #+#    #+#             */
/*   Updated: 2020/10/08 17:29:14 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int	c)
{
	c = (unsigned char)c;
	int i;

	i = 0;
	while (s[i])
		i++;
	if (c == '\0')
		return ((char	*)&s[i + 1]);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char	*)&s[i]);
		i--;
	}
	return 0;
}
