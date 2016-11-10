/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tho.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 09:47:37 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:42:33 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					tho(void)
{
	char			*str;

	if ((str = tgetstr("ho", NULL)) == NULL)
	{
		ft_putendl("Impossible cursor motion to the upper left corner");
		return (-1);
	}
	tputs(str, 1, ft_outc);
	return (0);
}
