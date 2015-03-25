/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 18:12:09 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/25 22:35:41 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


/*
**	This function will modify the shell behavement.
*/
int		ft_init_termios(t_all *all)
{
	struct winsize win;

	all->enter = 0;
	if (tgetent(NULL, getenv("TERM")) < 1)
		return (0);
	if (tcgetattr(0, &(all->term)) == -1)
		return (0);
	all->term.c_lflag &= ~(ICANON | ECHO);
	all->term.c_cc[VMIN] = 1;
	all->term.c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	all->nb_col = win.ws_col;
	all->nb_row = win.ws_row;
	if (tcsetattr(0, 0, &(all->term)) == -1)
		return (0);
	tputs(tgetstr("ti", NULL), 1, ft_myputchar);
	tputs(tgetstr("vi", NULL), 1, ft_myputchar);
	return (1);
}

/*
**	This function will reset the shell with default's configuration
*/
int		ft_end_termios(t_all *all)
{
	all->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(all->term)) == -1)
		return (0);
	tputs(tgetstr("te", NULL), 1, ft_myputchar);
	tputs(tgetstr("ve", NULL), 1, ft_myputchar);
	if (all->enter)
		ft_print_enter(all);
	return (1);
}
