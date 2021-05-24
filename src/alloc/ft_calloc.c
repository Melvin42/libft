/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 23:26:18 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:20:08 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** The ft_calloc() function allocates memory for an array of nmemb elements of
** size bytes each and returns a pointer to the allocated memory. The memory is
** set to zero. If nmemb or size is 0, then ft_calloc() returns either NULL, or
** a unique pointer value that can later be successfully passed to free().
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
