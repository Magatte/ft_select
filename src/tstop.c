/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 13:24:28 by pba               #+#    #+#             */
/*   Updated: 2016/02/18 11:42:15 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_select.h"
#include "tglobal.h"

void				tstop(void)
{
	t_termios		term;
	char			get_out[2];

	g_old_term = tinit(&term);
	traw(g_old_term);
	treset(g_sterm, 0);
	tclear();
	tve();
	get_out[0] = g_sterm->c_cc[VSUSP];
	get_out[1] = '\0';
	ioctl(0, TIOCSTI, get_out);
	signal(SIGTSTP, SIG_DFL);
}
