/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_delete_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 08:30:39 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 10:06:52 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tglobal.h"

static void			correct_numbers(t_dlist *list)
{
	int				i;
	t_dcell			*tmp;

	i = 1;
	tmp = list->head;
	while (tmp->next != list->head)
	{
		tmp->number = i;
		i++;
		tmp = tmp->next;
	}
	tmp->number = i;
}

static void			relink(t_dcell *tmp, t_dlist *list)
{
	if (tmp->next == list->head)
	{
		tmp->next = list->head->next;
		list->head = tmp->next;
		list->head->prev = tmp;
	}
	else
	{
		tmp->next = tmp->next->next;
		tmp->next->prev = tmp;
	}
}

int					dlist_delete_one(t_dlist *list)
{
	int				i;
	t_dcell			*tmp;
	t_dcell			*tmp_del;

	i = 1;
	if (list->len-- == 1 || list->all == 1)
	{
		tclear();
		return (0);
	}
	tmp = list->head->prev;
	while (i++ < list->pos)
		tmp = tmp->next;
	tmp_del = tmp->next;
	relink(tmp, list);
	free(tmp_del);
	correct_numbers(list);
	tresize(0, 0);
	return (1);
}
