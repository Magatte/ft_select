/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 12:53:08 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:24:04 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tglobal.h"

int					tmove(int key)
{
	if (key == TKEY_UP)
		tresize(-1, 0);
	else if (key == TKEY_DOWN)
		tresize(1, 0);
	else if (key == TKEY_LEFT)
		tresize(-(g_term_rows - 1), 0);
	else if (key == TKEY_RIGHT)
		tresize(g_term_rows - 1, 0);
	else if (key == TKEY_SPACE)
	{
		tresize(0, 1);
		tresize(1, 0);
	}
	return (0);
}
