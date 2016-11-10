/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 19:33:52 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:26:27 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				treset(t_termios *term, int tget_key)
{
	if (tcsetattr(0, TCSADRAIN, term) == -1)
	{
		ft_putstr_fd("term reset failed\n", 2);
		return (-1);
	}
	if (tget_key == 0)
	{
		tclear();
		ft_putstr_fd("\033[?1049l", 2);
	}
	return (0);
}
