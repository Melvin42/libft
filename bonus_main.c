/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:50:45 by melperri          #+#    #+#             */
/*   Updated: 2020/10/15 13:22:23 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printlst(t_list *begin)
{
	if (begin)
		while (begin)
		{
			printf("%s\n", (char *)begin->content);
			begin = begin->next;
		}
}

int main(void)
{
	t_list		*begin;
	t_list		*elem;
	t_list		*elem1;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;

	begin = ft_lstnew("coucou");
	elem = ft_lstnew("lorem");
	elem1 = ft_lstnew("ipsum");
	elem2 = ft_lstnew("dolor");
	elem3 = ft_lstnew("sit");
	elem4 = ft_lstnew("hibou");
	ft_lstadd_front(&begin, elem);
	ft_lstadd_front(&elem, elem1);
	ft_lstadd_front(&elem1, elem2);
	ft_lstadd_front(&elem2, elem3);
	ft_lstadd_front(&elem3, elem4);
	printlst(elem4);
	return (0);
}