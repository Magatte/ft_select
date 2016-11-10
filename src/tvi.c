/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tvi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 04:49:27 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:21:52 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					tvi(void)
{
	char			*str;

	if ((str = tgetstr("vi", NULL)) == NULL)
	{
		ft_putendl("Cursor invisible mode activated");
		return (-1);
	}
	tputs(str, 1, ft_outc);
	return (0);
}
