/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:16:22 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/04/16 18:14:12 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	**ft_lstdup(t_list *lst)
{
	t_list	**ret;
	t_list	**ptr;

	if (!(ret = (t_list**)malloc(sizeof(t_list*))))
		return (NULL);
	if (lst)
	{
		if (!(*ret = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		(*ret)->content = lst->content;
		if (!(ptr = ft_lstdup(lst->next)))
		{
			free(*ret);
			free(ret);
			return (NULL);
		}
		(*ret)->next = *ptr;
	}
	else
		*ret = NULL;
	return (ret);
}

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
