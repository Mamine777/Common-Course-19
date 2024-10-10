/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:34:43 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/10 17:14:30 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*nelt;

	if (!lst)
		return (NULL);
	node = lst;
	nelt = NULL;
	while (node != NULL)
	{
		ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&node, (*del));
			return (NULL);	
		}
		ft_lstadd_back(&nelt, node);
		node = node->next;
	}
	return (nelt);
}
