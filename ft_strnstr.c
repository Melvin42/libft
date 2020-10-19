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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i] == little[j])
			{
				j++;
				i++;
			}
		}
		ft_putnbr_fd((int)j, 1);
		if (little[j] == '\0' && little[j - 1] == big[i - 1])
			return ((char *)big);
		if (j == ft_strlen(little))
			i--;
		big++;
		i++;
	}
	return ((char *)NULL);
}

int	main()
{
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 30));
	return (0);
}
