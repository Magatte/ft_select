/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tglobal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 17:57:32 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 09:20:42 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TGLOBAL_H
# define TGLOBAL_H
# include "ft_select.h"

extern t_dlist				*g_list;
extern t_termios			*g_sterm;
extern t_termios			*g_old_term;
extern int					g_term_rows;

#endif
