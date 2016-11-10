/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdisplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 06:25:43 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:56:32 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include "ft_select.h"
#include "tglobal.h"

static void				column_display(t_dcell *cell, int *tab_max)
{
	int					offset;
	int					col;

	offset = 0;
	col = cell->number / (g_term_rows - 1);
	if (col > 0)
		offset = tab_max[col - 1];
	tcm(offset, cell->number - (col * (g_term_rows - 1)));
}

static void				underline(t_dcell *cell, int hl, int *tab_max)
{
	if (hl == 1)
	{
		if (cell->dswitch == 1)
			cell->dswitch = 0;
		else
			cell->dswitch = 1;
	}
	if (cell->dswitch == 1)
	{
		tus();
		tso();
		ft_putstr_fd((char*)cell->data, 2);
		tse();
		tue();
		column_display(cell, tab_max);
	}
	else
	{
		tus();
		ft_putstr_fd((char*)cell->data, 2);
		tue();
		column_display(cell, tab_max);
	}
}

static void				bareline(t_dcell *cell, int *tab_max)
{
	if (cell->dswitch == 1)
	{
		tso();
		ft_putstr_fd((char*)cell->data, 2);
		tse();
		column_display(cell, tab_max);
	}
	else
	{
		ft_putstr_fd((char*)cell->data, 2);
		column_display(cell, tab_max);
	}
}

static void				writeline(t_dcell *cell, int pos, int hl, int *tab_max)
{
	struct stat			*state;

	state = (struct stat *)malloc(sizeof(*state));
	if (stat((char *)cell->data, state) == 0)
	{
		if (state->st_mode & S_IFDIR)
			ft_putstr_fd("\033[36;01m", 2);
		else if (state->st_mode & S_IXUSR)
			ft_putstr_fd("\033[31;01m", 2);
	}
	if (pos == cell->number)
		underline(cell, hl, tab_max);
	else
		bareline(cell, tab_max);
	ft_putstr_fd("\033[0m", 2);
	free(state);
}

void					tdisplay(t_dlist *list, int direction, int hl)
{
	t_dcell			*tmp;
	int				*tab_max;

	tclear();
	tab_max = dlist_block_max(g_list, g_term_rows);
	tmp = list->head;
	if (tmp && tab_max)
	{
		list->pos = list->pos + direction;
		if (list->pos > list->len)
			list->pos = 1;
		else if (list->pos < 1)
			list->pos = list->len;
		while (tmp->next != list->head)
		{
			writeline(tmp, list->pos, hl, tab_max);
			tmp = tmp->next;
		}
		writeline(tmp, list->pos, hl, tab_max);
		ft_putchar_fd('\n', 2);
	}
	ft_memset(tab_max, 0, (g_list->len + g_term_rows - 2) / (g_term_rows - 1));
}
