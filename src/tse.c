/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tse.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 00:32:56 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:23:42 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					tse(void)
{
	char			*str;

	if ((str = tgetstr("se", NULL)) == NULL)
	{
		ft_putendl("Standout mode not desactivated");
		return (-1);
	}
	tputs(str, 1, ft_outc);
	return (0);
}
