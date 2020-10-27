/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:27:13 by melperri          #+#    #+#             */
/*   Updated: 2020/10/13 16:09:02 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	total;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (i > size)
		total = size + j;
	else
		total = i + j;
	if (total >= size && size <= i)
		return (total);
	j = 0;
	while (src[j] && i + 1 < size)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (total);
}
/*
int	main()
{
	char *dest;
//	char dest2[] = "coucou";
	
	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 15);
	
	printf("%ld\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
	printf("%s\n", dest);
//	printf("%ld\n", strlcat(dest2, "lorem ipsum dolor sit amet", 6));
	return (0);
}
*/
