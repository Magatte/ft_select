/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_max_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 14:06:26 by pba               #+#    #+#             */
/*   Updated: 2015/07/25 14:14:48 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				dlist_max_len(dlist *list)
{
	size_t		len;
	dcell		*tmp;

	len = 0;
	tmp = list->head;
	while (tmp->next != list->head)
	{
		if (len < ft_strlen(tmp->data))
			len = ft_strlen(tmp->data);
		tmp = tmp->next;
	}
	if (len < ft_strlen(tmp->data))
		len = ft_strlen(tmp->data);
	return (len);
}
