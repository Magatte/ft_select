/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 13:35:34 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:27:31 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					tso(void)
{
	char			*str;

	if ((str = tgetstr("so", NULL)) == NULL)
	{
		ft_putendl("Standout mode activated");
		return (-1);
	}
	tputs(str, 1, ft_outc);
	return (0);
}
