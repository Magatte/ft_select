/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tve.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 04:41:06 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:21:33 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					tve(void)
{
	char			*str;

	if ((str = tgetstr("ve", NULL)) == NULL)
	{
		ft_putendl("Cursor visible mode activated");
		return (-1);
	}
	tputs(str, 1, ft_outc);
	return (0);
}
