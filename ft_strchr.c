/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:25:59 by melperri          #+#    #+#             */
/*   Updated: 2020/10/08 17:26:04 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int	c)
{
	c = (unsigned char)c;
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char	*)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return 0;
}
