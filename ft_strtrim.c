/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:39:35 by melperri          #+#    #+#             */
/*   Updated: 2020/10/09 15:16:08 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{	
	char	*str;
	int		i;
	int		size;
	int		j;

	i = 0;
	size = ft_strlen(s);
	while (ft_isset(s[i], set))
		i++;
	while (ft_isset(s[size - 1], set))
		size--;
	size = size - i;
	if (!(str = malloc(sizeof(str) * size + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (ft_isset(s[i], set))
		i++;
	while (j < size)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
