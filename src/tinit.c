/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 19:24:46 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:26:05 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_termios				*tinit(t_termios *term)
{
	t_termios		*cterm;
	char			*name_term;

	ft_putstr_fd("\033[?1049h\033[H", 2);
	cterm = (t_termios *)malloc(sizeof(*term));
	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_putendl("Error : attempt to get the name of the term failed");
		return (NULL);
	}
	if (tgetent(NULL, name_term) < 1)
	{
		ft_putendl("Error : this term doesn't exist in our data base");
		return (NULL);
	}
	if (tcgetattr(0, term) == -1)
	{
		ft_putendl("Error : " \
				"attempt to get the attributes of get the current term failed");
		return (NULL);
	}
	cterm = ft_memcpy(cterm, term, sizeof(*term));
	return (cterm);
}
