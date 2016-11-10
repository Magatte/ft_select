/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 08:48:58 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:24:23 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				traw(t_termios *term)
{
	term->c_lflag &= ~(ECHO | ECHONL | ICANON | ECHOE | ECHOK);
	term->c_lflag |= (ISIG);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		ft_putstr("Term attributes couldn't be set");
}
