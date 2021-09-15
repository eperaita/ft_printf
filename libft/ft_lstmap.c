/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:29:17 by eperaita          #+#    #+#             */
/*   Updated: 2021/08/16 14:56:52 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),	void (*del)(void *))
{
	t_list	*head;
	t_list	*to_add;

	if (!lst || !f)
		return (0);
	head = NULL;
	while (lst)
	{
		to_add = ft_lstnew((*f)(lst->content));
		if (!to_add)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, to_add);
		lst = lst->next;
	}
	return (head);
}
