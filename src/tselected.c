/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tselected.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 05:07:59 by pba               #+#    #+#             */
/*   Updated: 2015/10/06 10:40:19 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include "ft_select.h"

static void			get_state(t_dcell *cell)
{
	struct stat		*state;

	state = (struct stat *)malloc(sizeof(*state));
	if (stat((char *)cell->data, state) == 0)
	{
		if (state->st_mode & S_IFDIR)
			ft_putstr_fd((char*)cell->data, 1);
		else if (state->st_mode & S_IXUSR)
			ft_putstr_fd((char*)cell->data, 1);
		else
			ft_putstr_fd((char*)cell->data, 1);
	}
	else
		ft_putstr_fd((char*)cell->data, 1);
	free(state);
}

int					tselected(t_dlist *list)
{
	t_dcell			*tmp;

	tclear();
	tmp = list->head;
	while (tmp->next != list->head)
	{
		if (tmp->dswitch == 1)
		{
			get_state(tmp);
			ft_putchar_fd(' ', 1);
		}
		tmp = tmp->next;
	}
	if (tmp->dswitch == 1)
		get_state(tmp);
	ft_putchar_fd('\n', 1);
	return (1);
}
