/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tclear.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 12:32:46 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:35:26 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				tclear(void)
{
	char		*res;

	if ((res = tgetstr("cd", NULL)) == NULL)
	{
		ft_putstr_fd("Attempt to clear the term failed", 2);
		return (-1);
	}
	tho();
	tputs(res, 2, ft_outc);
	tvi();
	return (0);
}
