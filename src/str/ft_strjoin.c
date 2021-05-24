/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:56:30 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 16:02:07 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** Alloue (avec malloc(3)) et retourne une nouvelle
** chaine, résultat de la concaténation de s1 et s2.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*join;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}
