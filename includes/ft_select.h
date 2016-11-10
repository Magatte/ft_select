/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/02 15:00:54 by pba               #+#    #+#             */
/*   Updated: 2015/10/07 06:58:31 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <termios.h>
# include <term.h>
# include <curses.h>
# include "libft.h"

# define TKEY_UP			4283163
# define TKEY_DOWN			4348699
# define TKEY_LEFT			4479771
# define TKEY_RIGHT			4414235
# define TKEY_ESC			27
# define TKEY_SPACE			32
# define TKEY_RETURN		10
# define TKEY_BACK			127
# define TKEY_DEL			2117294875
# define TKEY_TAB			9
# define TKEY_CTRL_C		3
# define TKEY_CTRL_A		1

typedef	struct				s_dcell
{
	int						dswitch;
	int						number;
	void					*data;
	struct s_dcell			*prev;
	struct s_dcell			*next;
}							t_dcell;
typedef struct				s_dlist
{
	int						pos;
	int						all;
	int						len;
	struct s_dcell			*head;
}							t_dlist;
typedef struct termios		t_termios;
typedef struct winsize		t_winsize;
t_dlist						*dlist_new(void);
t_dlist						*dlist_append(t_dlist *list,
							void *newdata, int number);
size_t						dlist_max_len(t_dlist *list);
size_t						dlist_total_len(t_dlist *list);
void						dlist_display(t_dlist *list);
int							dlist_delete_one(t_dlist *list);
t_termios					*tinit(t_termios *term);
void						traw(t_termios *term);
int							treset(t_termios *term, int tget_key);
int							tget_key(t_dlist *list);
int							tmove(int key);
void						tdisplay(t_dlist *list, int direction, int hl);
int							*dlist_block_max(t_dlist *list, int block_len);
void						tresize(int direction, int hl);
int							tselected(t_dlist *list);
int							tselected_all(t_dlist *list);
int							ft_outc(int c);
int							tclear();
int							tcr();
int							tho();
int							tus();
int							tue();
int							tso();
int							tse();
int							tve();
int							tvi();
int							tcm();
void						tsignal();
void						tstop();
void						tcont();

#endif
