/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tue.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 21:05:55 by pba               #+#    #+#             */
/*   Updated: 2015/10/06 10:11:21 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					tue(void)
{
	char			*str;

	if ((str = tgetstr("ue", NULL)) == NULL)
	{
		ft_putendl_fd("Underline mode not ended.", 2);
		return (-1);
	}
	tputs(str, 1, ft_outc);
	return (0);
}
