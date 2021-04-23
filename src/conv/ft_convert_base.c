/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:49:08 by melperri          #+#    #+#             */
/*   Updated: 2021/01/25 13:39:04 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*dest;

	if (!((checkbase(base_from) && checkbase(base_to))))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	dest = ft_itoa_base(nb, base_to);
	return (dest);
}
