/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 16:10:38 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 07:18:06 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dlist			*dlist_append(t_dlist *list, void *newdata, int number)
{
	t_dcell		*newcell;

	if (list)
	{
		if ((newcell = (t_dcell *)malloc(sizeof(t_dcell))))
		{
			newcell->data = newdata;
			if (list->head == NULL)
			{
				list->head = newcell;
				newcell->prev = list->head;
				newcell->next = list->head;
			}
			else
			{
				newcell->next = list->head;
				newcell->prev = list->head->prev;
				list->head->prev->next = newcell;
				list->head->prev = newcell;
			}
			newcell->number = number;
			list->len++;
		}
	}
	return (list);
}
