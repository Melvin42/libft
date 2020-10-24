#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstmap;

	if (lst)
	{
		lstmap = ft_lstnew(lst->content);
		while (lst->next)
		{
			lstmap->content = (*f)(lst->content);
			if (!(lstmap->content))
			{
				ft_lstclear(&lstmap, del);
			}
			lstmap->next = lst->next;
			lst = lst->next;
		}
	}
	return (lstmap);
}
