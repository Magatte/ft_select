/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 19:22:50 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:29:31 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_select.h"
#include "tglobal.h"

t_dlist			*dlist_new(void)
{
	t_dlist		*new;

	new = NULL;
	if ((new = (t_dlist*)malloc(sizeof(t_dlist))))
	{
		new->pos = 1;
		new->all = 0;
		new->len = 0;
		new->head = NULL;
	}
	return (new);
}
