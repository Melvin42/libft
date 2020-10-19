/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:39:35 by melperri          #+#    #+#             */
/*   Updated: 2020/10/12 15:49:18 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_isset(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{	
	char			*str;
	unsigned int	i;
	size_t			size;

	i = 0;
	size = ft_strlen(s);
	while (ft_isset(s[i], set))
		i++;
	while (s[i] != '\0' && ft_isset(s[size - 1], set))
		size--;
	size = size - i;
	str = ft_substr(s, i, size);
	return (str);
}
/*
int	main()
{
	printf("%s\n", ft_strtrim("  lorem  ", " m"));
	printf("%s\n", ft_strtrim("        ", " "));
	return (0);
}
*/
