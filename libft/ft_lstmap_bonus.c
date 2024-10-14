/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:34:43 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/14 11:47:43 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	t_list	*last_elem;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	last_elem = NULL;
	while (lst != NULL)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (!new_list)
			new_list = new_elem;
		else
			last_elem->next = new_elem;
		last_elem = new_elem;
		lst = lst->next;
	}
	return (new_list);
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>
// int main()
// {
// 	t_list *lst = ft_lstnew("coco");
// 	t_list	*second_node = ft_lstnew("cazzo");

// 	lst->next = second_node;
// 	t_list	*new_list = ft_lstmap(lst, ft_toupper, delete_content);

// 	printf("Original list:\n");
// 	t_list	*temp = lst;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}

// 	printf("\nMapped list (uppercase):\n");
// 	temp = new_list;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}

// 	ft_lstclear(&lst, delete_content);
// 	ft_lstclear(&new_list, delete_content);
// }