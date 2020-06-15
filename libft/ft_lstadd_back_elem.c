/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <fyusuf-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:29:15 by fyusuf-a          #+#    #+#             */
/*   Updated: 2020/06/15 18:20:47 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back_elem(t_list **alst, void *data)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (1);
	new->content = data;
	new->next = NULL;
	if (*alst == NULL)
		*alst = new;
	else
		ft_lstadd_back(&((*alst)->next), new);
	return (0);
}
