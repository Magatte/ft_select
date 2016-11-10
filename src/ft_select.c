/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/02 10:09:01 by pba               #+#    #+#             */
/*   Updated: 2015/10/08 03:12:49 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "tglobal.h"
#include "libft.h"

t_dlist				*g_list;
t_termios			*g_sterm;
t_termios			*g_old_term;
int					g_term_rows;

int					main(int ac, char **av)
{
	int				i;
	t_termios		term;

	i = 0;
	if (ac > 1)
	{
		if ((g_sterm = tinit(&term)) == NULL)
			return (0);
		tsignal();
		g_list = dlist_new();
		while (++i < ac)
			g_list = dlist_append(g_list, (void*)av[i], i);
		traw(&term);
		tresize(0, 0);
		treset(g_sterm, tget_key(g_list));
		tve();
	}
	else
		ft_putstr_fd("\033[31;01mNo argument given.\n\033[0m", 2);
	return (0);
}
