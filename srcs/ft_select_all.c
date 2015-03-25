/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 18:19:24 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/25 22:25:01 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	ft_deselect_all will unselect all elements if all elements are selected.
*/
void	ft_deselect_all(t_all *all)
{
	t_lst	*tmp;

	all->lst->select = 0;
	tmp = all->lst->next;
	while (tmp != all->lst)
	{
		tmp->select = 0;
		tmp = tmp->next;
	}
}

/*
**	ft_select_all will select all elements if one element isn't selected
**	else if all elements are selected ft_deselect_all is called.
*/
void	ft_select_all(t_all *all)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	if (all->lst->select == 0)
	{
		all->lst->select = 1;
		i = 1;
	}
	tmp = all->lst->next;
	while (tmp != all->lst)
	{
		if (tmp->select == 0)
		{
			tmp->select = 1;
			i = 1;
		}
		tmp = tmp->next;
	}
	if (!i)
		ft_deselect_all(all);
}
