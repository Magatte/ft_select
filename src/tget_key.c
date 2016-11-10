/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tget_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 19:29:47 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:25:37 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "tglobal.h"

int				tget_key(t_dlist *list)
{
	int			*buf;
	int			loop;

	loop = 1;
	buf = (int *)malloc(sizeof(int));
	*buf = 0;
	while (loop)
	{
		ft_memset(buf, 0, 4);
		read(0, buf, 4);
		if (*buf == TKEY_ESC)
			break ;
		else if (*buf == TKEY_UP || *buf == TKEY_DOWN || *buf == TKEY_LEFT ||
				*buf == TKEY_RIGHT || *buf == TKEY_SPACE)
			tmove(*buf);
		else if (*buf == TKEY_RETURN)
			return (tselected(list));
		else if (*buf == TKEY_BACK || *buf == TKEY_DEL)
			loop = dlist_delete_one(g_list);
		else if (*buf == TKEY_CTRL_A)
			tselected_all(g_list);
	}
	return (0);
}
