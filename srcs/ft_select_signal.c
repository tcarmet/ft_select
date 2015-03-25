/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 18:23:18 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/25 22:35:16 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	ft_sig_stop will be called when the SIGSTP signal is on.
**	This function will put the process on hold and will restablish
**	the terminal.
*/
static	void	ft_sig_stop(void)
{
	t_all	*all;
	char	cp[2];

	all = NULL;
	all = ft_stock(all, 1);
	cp[0] = all->term.c_cc[VSUSP];
	cp[1] = 0;
	all->term.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	ft_clear_screen();
	tcsetattr(0, 0, &(all->term));
	tputs(tgetstr("te", NULL), 1, ft_myputchar);
	tputs(tgetstr("ve", NULL), 1, ft_myputchar);
	ioctl(0, TIOCSTI, cp);
}

/*
**	ft_sig_cont will be called when the SIGCONT signal is on.
**	This function will restablish the program.
*/
static void		ft_sig_cont(void)
{
	t_all *all;

	all = NULL;
	all = ft_stock(all, 1);
	all->term.c_lflag &= ~(ICANON | ECHO);
	all->term.c_cc[VMIN] = 1;
	all->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(all->term));
	tputs(tgetstr("ti", NULL), 1, ft_myputchar);
	tputs(tgetstr("vi", NULL), 1, ft_myputchar);
	signal(SIGTSTP, ft_catch_signal);
	ft_resize();
	ft_check_size(all);
}

/*
**	ft_interrupt is called when a SIGINT or any other signal is on.
**	And it will reset the shell with default's configuration.
*/
static	void	ft_interrupt(void)
{
	t_all *all;

	all = NULL;
	all = ft_stock(all, 1);
	ft_end_termios(all);
	exit(0);
}

/*
**	ft_catch_signal get the signal given by ft_signal and will conduct to
**	the right signal function depending of the catched signal.
*/
void			ft_catch_signal(int i)
{
	if (i == SIGCONT)
		ft_sig_cont();
	else if (i == SIGTSTP)
		ft_sig_stop();
	else if (i == SIGWINCH)
		ft_resize();
	else
		ft_interrupt();
}

/*
**	ft_signal will collect any kind of signal and will give
**	the right instruction to ft_catch_signal at any time
**	during the execution of the program.
*/
void			ft_signal(void)
{
	int i;

	i = 1;
	while (i < 32)
	{
		signal(i, ft_catch_signal);
		i++;
	}
}
