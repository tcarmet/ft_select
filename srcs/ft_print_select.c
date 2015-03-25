/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 15:18:19 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/25 22:24:15 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** This function will underline and print the current string.
*/
void	ft_under_line(char *str)
{
	tputs(tgetstr("us", NULL), 1, ft_myputchar);
	ft_putstr_fd("\033[36m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[00m", 2);
	tputs(tgetstr("ue", NULL), 1, ft_myputchar);
}

/*
** This function will print the reverse video mode on the selected string.
*/
void	ft_print_select(char *str)
{
	tputs(tgetstr("so", NULL), 1, ft_myputchar);
	ft_putstr_fd("\033[36m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[00m", 2);
	tputs(tgetstr("se", NULL), 1, ft_myputchar);
}

/*
**	This function will print the underline and reverse video
** 	mode on the selected and current string.
*/
void	ft_select_underline(char *str)
{
	tputs(tgetstr("us", NULL), 1, ft_myputchar);
	tputs(tgetstr("so", NULL), 1, ft_myputchar);
	ft_putstr_fd("\033[36m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[00m", 2);
	tputs(tgetstr("se", NULL), 1, ft_myputchar);
	tputs(tgetstr("ue", NULL), 1, ft_myputchar);
}

/*
** This function will select the right behavement for the string output.
*/
void	ft_select_behavement(t_lst *lst)
{
	if (lst->line == 1 && lst->select == 1)
		ft_select_underline(lst->value);
	else if (lst->line == 1)
		ft_under_line(lst->value);
	else if (lst->select == 1)
		ft_print_select(lst->value);
	else
		ft_putendl_fd(lst->value, 2);
}

/*
** This function will print the list.
*/
void	ft_print_list_select(t_all *all)
{
	t_lst	*tmp;

	tmp = NULL;
	ft_select_behavement(all->lst);
	tmp = all->lst->next;
	while (tmp != all->lst)
	{
		ft_select_behavement(tmp);
		tmp = tmp->next;
	}
}
