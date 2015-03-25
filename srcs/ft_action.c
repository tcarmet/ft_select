/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 19:31:34 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/25 22:21:28 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	ft_goto_begin will go to the first string of the list.
*/
void	ft_goto_begin(t_all *all)
{
	t_lst	*tmp;

	tmp = all->lst;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	all->lst->line = 1;
}

/*
**	ft_goto_end will go to the last string of the list.
*/
void	ft_goto_end(t_all *all)
{
	t_lst	*tmp;

	tmp = all->lst;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	all->lst->prev->line = 1;
}

/*
**	This function will reverse video mode on the current string and move
**	the cursor down.
*/
void	ft_space_key(t_all *all)
{
	t_lst	*tmp;

	tmp = all->lst;
	while (tmp->line != 1)
		tmp = tmp->next;
	if (tmp->select == 0)
		tmp->select = 1;
	else
		tmp->select = 0;
	tmp->line = 0;
	tmp->next->line = 1;
}

/*
**	This function will delete the current selected string
**	and move the cursor down.
*/
int		ft_delete(t_all *all)
{
	t_lst	*tmp;

	if (all->lst == all->lst->next)
	{
		free(all->lst);
		return (0);
	}
	tmp = all->lst;
	if (all->lst->line == 1)
		all->lst = tmp->next;
	else
	{
		while (tmp->line != 1)
			tmp = tmp->next;
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->next->line = 1;
	free(tmp->value);
	free(tmp);
	ft_count_col(all);
	all->count[LINE] -= 1;
	return (1);
}

/*
**	ft_tab_key will clear the selection, and will reverse video mode on 
**	the current string, and move the cursor down.
*/
void	ft_tab_key(t_all *all)
{
	ft_deselect_all(all);
	ft_space_key(all);
}
