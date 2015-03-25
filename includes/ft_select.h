/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 15:42:48 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/25 18:30:21 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft.h"
# include <signal.h>
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <sys/ioctl.h>
# define BUFFER *(unsigned int *)buffer
# define LINE 0
# define COL 1

typedef struct		s_lst
{
	char			*value;
	int				select;
	int				line;
	struct s_lst	*next;
	struct s_lst	*prev;
	int				len;
}					t_lst;

typedef enum	e_enum
{
	LEFT_KEY = 4479771,
	RIGHT_KEY = 4414235,
	UP_KEY = 4283163,
	DOWN_KEY = 4348699,
	ESC_KEY = 27,
	SPACE_KEY = 32,
	DEL_KEY = 127,
	RET_KEY = 10,
	SUP_KEY = 2117294875,
	HOME_KEY = 4741915,
	END_KEY = 4610843,
	PAGE_UP_KEY = 2117425947,
	PAGE_DOWN_KEY = 2117491483,
	TAB_KEY = 9,
	CRTL_A_KEY = 1,
}				t_enum;

typedef struct		s_all
{
	struct termios	term;
	char			*name_term;
	int				nb_col;
	int				nb_row;
	int				enter;
	int				count[2];
	char			**ret_tab;
	t_lst			*lst;
}					t_all;

/*
**	ft_term_change.c
*/
int					ft_init_termios(t_all *all);
int					ft_end_termios(t_all *all);
/*
**	ft_print_select.c
*/
void				ft_print_list_select(t_all *all);
void				ft_under_line(char *str);
void				ft_select_underline(char *str);
void				ft_select_behavement(t_lst *lst);
void				ft_print_select(char *str);
/*
**	ft_myputchar.c
*/
int					ft_myputchar(int c);
/*
**	ft_select.c
*/
int					ft_brain_select(char **argv, t_all *all);
/*
**	ft_list.c
*/
void				ft_arg_to_list(char **argv, t_all *all);
/*
**	ft_select_misc.c
*/
t_all				*ft_stock(t_all *all, int i);
void				ft_clear_screen(void);
/*
**	ft_keyhook.c
*/
int					ft_keyhook(t_all *all);
/*
**	ft_moves.c
*/
void				ft_move_up(t_all *all);
void				ft_move_down(t_all *all);
void				ft_tab_key(t_all *all);
/*
**	ft_action.c
*/
void				ft_space_key(t_all *all);
int					ft_delete(t_all *all);
void				ft_goto_begin(t_all *all);
void				ft_goto_end(t_all *all);
/*
**	ft_enter.c
*/
void				ft_print_enter(t_all *all);
void				ft_stock_tab(t_all *all);
void				ft_return_key(t_all *all);
/*
**	ft_select_all.c
*/
void				ft_select_all(t_all *all);
void				ft_deselect_all(t_all *all);
/*
**	ft_select_signal.c
*/
void				ft_signal(void);
void				ft_catch_signal(int i);
/*
**	ft_select_resize.c
*/
void				ft_resize(void);
int					ft_check_size(t_all *all);
void				ft_count_col(t_all *all);

#endif
