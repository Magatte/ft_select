/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 05:08:07 by pba               #+#    #+#             */
/*   Updated: 2015/10/06 07:32:11 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					tcm(int pos_x, int pos_y)
{
	char			*str;

	if ((str = tgetstr("cm", NULL)) == NULL)
	{
		ft_putendl_fd("Cursor movement mode not activated.", 2);
		return (-1);
	}
	tputs(tgoto(str, pos_x, pos_y), 1, ft_outc);
	return (0);
}
