/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 12:46:24 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/06/13 11:27:53 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstadd_front_elem(t_list **alst, void *data)
{
	t_list	*new;

	if (!alst)
		return (1);
	if (!(new = malloc(sizeof(t_list))))
		return (1);
	new->content = data;
	new->next = *alst;
	*alst = new;
	return (0);
}
