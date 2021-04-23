/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:51:30 by melperri          #+#    #+#             */
/*   Updated: 2020/11/18 19:54:59 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstbegin;
	t_list	*lstmap;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	lstbegin = ft_lstnew((*f)(lst->content));
	tmp = lstbegin;
	while (lst->next)
	{
		lst = lst->next;
		lstmap = ft_lstnew((*f)(lst->content));
		if (!(lstmap))
		{
			ft_lstclear(&lstbegin, del);
			return (NULL);
		}
		tmp->next = lstmap;
		tmp = lstmap;
	}
	return (lstbegin);
}
