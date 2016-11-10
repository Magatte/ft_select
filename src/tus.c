/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tus.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 20:54:32 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:22:24 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					tus(void)
{
	char			*str;

	if ((str = tgetstr("us", NULL)) == NULL)
	{
		ft_putendl("Underline mode not activated");
		return (-1);
	}
	tputs(str, 1, ft_outc);
	return (0);
}
