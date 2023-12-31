/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiliu <yiliu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:00:35 by yidiliu           #+#    #+#             */
/*   Updated: 2023/12/26 15:44:45 by yiliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*newlist;

	if (!lst || !f || !del)
		return (NULL);
	newlist = ft_lstnew(f(lst->content));
	if (!newlist)
		return (NULL);
	lst = lst->next;
	result = newlist;
	while (lst)
	{
		newlist->next = ft_lstnew(f(lst->content));
		if (!(newlist->next))
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		lst = lst->next;
		newlist = newlist->next;
	}
	return (result);
}
