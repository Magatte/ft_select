/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tselected_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 16:20:47 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 06:24:48 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "tglobal.h"

int					tselected_all(t_dlist *list)
{
	t_dcell			*tmp;
	int				all;

	if (list->all == 0)
		all = 1;
	else
		all = 0;
	tmp = list->head;
	while (tmp->next != list->head)
	{
		tmp->dswitch = all;
		tmp = tmp->next;
	}
	tmp->dswitch = all;
	list->all = all;
	tresize(0, 0);
	return (1);
}
