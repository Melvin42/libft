/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 12:39:35 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:48:58 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** Alloue (avec malloc(3)) et retourne une copie de la chaine ’s1’, sans les
** caractères spécifiés dans ’set’ au début et à la fin de la chaine de
** caractères.
*/

static int	ft_isset(char c, char const *set)
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

	if (!s || !set)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	while (ft_isset(s[i], set))
		i++;
	while (s[i] && ft_isset(s[size - 1], set))
		size--;
	size = size - i;
	str = ft_substr(s, i, size);
	return (str);
}
