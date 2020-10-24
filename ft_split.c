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

size_t     issep(char a, char c)
{
    if (a == c)
        return (1);
    else
        return (0);
}

size_t		countword(char const *s, char c)
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

char	**dupword(char const *s, char c, char **split, size_t wordsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while ((s[i] != c) && s[i])
			{
				i++;
				wordsize++;
			}
			if (wordsize != 0)
			{
				if (!(split[j] = malloc(sizeof(char) * wordsize)))
					return (NULL);
				ft_bzero(split[j], wordsize);
				ft_memcpy(split[j], s + i - wordsize, wordsize);
				split[j][wordsize] = '\0';
				j++;
				wordsize = 0;
			}
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t		cmpt;
	size_t	wordsize;

	cmpt = countword(s, c);
	if (!(split = malloc(sizeof(char *) * (cmpt + 1))))
		return (NULL);
	wordsize = 0;
	split = dupword(s, c, split, wordsize);
	split[cmpt] = NULL;
	return (split);
}
/*
int	main(void)
{
	char	asplit[] = "   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
	char	**split;
	size_t i;

	i = 0;
	split = ft_split(asplit, ' ');
	//split = ft_split("", 'z');
	while (i < 12)
	{
		printf("%s\n", split[i]);
		//ft_putstr_fd(split[i], 1);
		//ft_putchar_fd('\n', 1);
		i++;
	}
	return (0);
}
*/
