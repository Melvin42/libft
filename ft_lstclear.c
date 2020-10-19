/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:59:17 by melperri          #+#    #+#             */
/*   Updated: 2020/10/14 17:18:58 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (*lst)
		tmp = *lst;
	while (*lst)
	{
		if (*lst)
			tmp->next = *lst;
		else
			tmp = NULL;
		(*del)((t_list *)lst);
		*lst = tmp;
	}
}
