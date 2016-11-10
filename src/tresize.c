/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tresize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 12:01:56 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 06:15:11 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_select.h"
#include "tglobal.h"

static int				max_width(t_dcell *cell, size_t block_len)
{
	t_dcell				*tmp;
	int					max;
	size_t				i;
	size_t				len;

	tmp = cell;
	len = ft_strlen((char *)tmp->data);
	max = 0;
	i = 2;
	tmp = tmp->next;
	while (tmp != cell)
	{
		while (i < block_len && tmp != cell)
		{
			if (len < ft_strlen((char *)tmp->data))
				len = ft_strlen((char *)tmp->data);
			tmp = tmp->next;
			i++;
		}
		max += (int)len + 5;
		len = 0;
		i = 1;
	}
	return (max - 3);
}

static int				is_wide_enough(t_winsize *wsize)
{
	int					max_len;

	max_len = max_width(g_list->head, g_term_rows);
	if ((int)wsize->ws_col < max_len)
		return (0);
	return (1);
}

static void				is_high_enough(t_winsize *wsize, int direction, int hl)
{
	if ((is_wide_enough(wsize)) == 0)
	{
		tclear();
		ft_putstr_fd("\033[31;02mYou need to widen the term.\n\033[0m", 2);
	}
	else
		tdisplay(g_list, direction, hl);
}

void					tresize(int direction, int hl)
{
	t_winsize			wsize;

	if (ioctl(0, TIOCGWINSZ, &wsize) == -1)
		ft_putendl("Attempt to get the size of the current window failed");
	g_term_rows = wsize.ws_row;
	is_high_enough(&wsize, direction, hl);
}
