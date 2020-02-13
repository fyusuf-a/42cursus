/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:16:22 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/11/22 11:47:52 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstiter_acc(t_list *lst, void *(*f)(void *))
{
	if (!lst)
		return ;
	else
	{
		lst->content = f(lst->content);
		ft_lstiter_acc(lst->next, f);
	}
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	**ret;

	if (!(ret = ft_lstdup(lst)))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	ft_lstiter_acc(*ret, f);
	return (*ret);
}
