/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:25:32 by melperri          #+#    #+#             */
/*   Updated: 2020/10/09 18:18:55 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ischar(char s, char c)
{
    if (s == c)
        return (1);
    else
        return (0);
}

int		countword(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == 0)
		return (0);
	while (ischar(str[i], c))
		i++;
	while (str[i])
	{
		while (!(ischar(str[i], c)))
			i++;
		count++;
		while (ischar(str[i], c))
			i++;
	}
	return (count);
}

char	*ft_strncpyplus(char *dest, char const *src, int wordsize, int j)
{
	int	i;

	i = 0;
	while (src[j] && i < wordsize)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**dupword(char const *str, char c, char **split, int wordsize)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (ischar(str[i], c))
		i++;
	while (str[i])
	{
		if (!(ischar(str[i], c)))
		{
			while (!(ischar(str[i], c)))
			{
				i++;
				wordsize++;
			}
			if (!(split[j] = malloc(sizeof(char) * (wordsize + 1))))
				return (NULL);
			split[j] = ft_strncpyplus(split[j], str, wordsize, (i - wordsize));
			j++;
			wordsize = 0;
		}
		i++;
	}
	return (split);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	int		cmpt;

	cmpt = countword(str, c);
	if (!(split = malloc(sizeof(split) * (cmpt + 1))))
		return (NULL);
	split = dupword(str, c, split, 0);
	split[cmpt] = NULL;
	return (split);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**split;
	int i;

	i = 0;
	split = ft_split("hello les poulets", ' ');
	while (i < 4)
	{
		printf("%s\n", split[i]);
		i++;
	}
	return (0);
}*/
