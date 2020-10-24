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

void	ft_del(void *content)
{
	if (content)
	  free(content);
}

char *ft_rot1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = str[i] + 1;
		i++;
	}
	return (str);
}

int main(void)
{
	t_list		*begin;
	t_list		*elem;
	t_list		*elem1;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*elem5;
	char *str;
	t_list		*map;

	if (!(str = malloc(sizeof(str) * 6 + 1)))
	  return (0);
	str = ft_memcpy(str, "joujou", 6);

	begin = ft_lstnew("coucou");
	elem = ft_lstnew("lorem");
	elem1 = ft_lstnew("ipsum");
	elem2 = ft_lstnew("dolor");
	elem3 = ft_lstnew("sit");
	elem4 = ft_lstnew("hibou");
	elem5 = ft_lstnew(str);
	ft_lstadd_front(&begin, elem);
	ft_lstadd_front(&elem, elem1);
	ft_lstadd_front(&elem1, elem2);
	ft_lstadd_back(&begin, elem3);
	ft_lstadd_back(&begin, elem4);
	ft_lstadd_back(&begin, elem5);
	printlst(elem2);
	map = ft_lstmap(elem2, (void *)&ft_rot1, &ft_del);
	printlst(map);
	ft_lstclear(&elem2, &ft_del);
	return (0);
}
