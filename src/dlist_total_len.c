/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_total_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 05:51:23 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:29:57 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				dlist_total_len(dlist *list)
{
	size_t			len;
	dcell			*tmp;

	len = 0;
	tmp = list->head;
	while (tmp->next != list->head)
	{
		len = len + ft_strlen(tmp->data) + 1;
		tmp = tmp->next;
	}
	len = len + ft_strlen(tmp->data) + 1;
	return (len);
}
