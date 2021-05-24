/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:25:32 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:58:43 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static size_t	countword(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while ((s[i] != c) && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

static char	**freesplit(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	split = NULL;
	return (split);
}

static char	**dupword(char const *s, char c, char **split, size_t wordsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		while ((s[i] != c) && s[i++])
			wordsize++;
		if (wordsize != 0)
		{
			split[j] = malloc(sizeof(char) * wordsize + 1);
			if (!split[j])
				return (freesplit(split, j));
			ft_memcpy(split[j], s + i - wordsize, wordsize);
			split[j][wordsize] = '\0';
			j++;
			wordsize = 0;
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	size_t		cmpt;
	size_t		wordsize;

	if (!s)
		return (NULL);
	cmpt = countword(s, c);
	split = malloc(sizeof(char *) * (cmpt + 1));
	if (!split)
		return (NULL);
	wordsize = 0;
	split = dupword(s, c, split, wordsize);
	split[cmpt] = NULL;
	return (split);
}
