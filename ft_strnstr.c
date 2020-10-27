/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:31:15 by melperri          #+#    #+#             */
/*   Updated: 2020/10/13 14:22:23 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strnstr() function locates the first occurrence of the null-terminated
** string little in the string big, where not more than len characters are
** searched. Characters that appear after a ‘\0’ character are not searched.
** Since the ft_strnstr() function is a FreeBSD specific API,
** it should only be used when portability is not a concern.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i] == little[j] && little[j] && i < len)
			{
				j++;
				i++;
			}
			if ((little[j] == '\0') && little[j - 1] == big[i - 1])
				return ((char *)&big[i - j]);
			if (j == ft_strlen(little))
				i -= j;
		}
		i++;
	}
	return ((char *)NULL);
}
/*
int	main()
{
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 30));
	return (0);
}
*/
