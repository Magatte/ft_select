/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsignal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 21:02:38 by pba               #+#    #+#             */
/*   Updated: 2016/02/18 17:31:16 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_select.h"
#include "tglobal.h"

static void				sig_handler(int sig_no)
{
	if (sig_no == SIGWINCH)
		tresize(0, 0);
	else if (sig_no == SIGTSTP)
		tstop();
	else if (sig_no == SIGCONT)
		tcont();
	else
	{
		treset(g_sterm, 0);
		tclear();
		tve();
		exit(sig_no);
	}
}

void					tsignal(void)
{
	int					sig_no;

	sig_no = 0;
	while (sig_no <= 31)
	{
		if (sig_no != SIGKILL
				&& sig_no != SIGSTOP
				&& sig_no != SIGCHLD
				&& sig_no != SIGURG
				&& sig_no != SIGIO)
			signal(sig_no, sig_handler);
		sig_no++;
	}
}
