/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 18:17:12 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/25 22:21:59 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	This function will print the end the selected string
**	into the terminal output.
*/
void	ft_print_enter(t_all *all)
{
	int		i;

	i = 0;
	while (all->ret_tab[i])
	{
		ft_putstr(all->ret_tab[i]);
		if (all->ret_tab[i + 1])
			ft_putchar(32);
		i++;
	}
}

/*
**	This function will put the select string into ret_tab.
*/
void	ft_stock_tab(t_all *all)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	if (all->lst->select == 1)
	{
		all->ret_tab[i] = ft_strdup(all->lst->value);
		i++;
	}
	tmp = all->lst->next;
	while (tmp != all->lst)
	{
		if (tmp->select == 1)
		{
			all->ret_tab[i] = ft_strdup(tmp->value);
			i++;
		}
		tmp = tmp->next;
	}
	all->ret_tab[i] = 0;
}

/*
**	This function will count how much select string are on and
**	will allocate enough memory into ret_tab.
*/
void	ft_return_key(t_all *all)
{
	t_lst	*tmp;
	int		count;

	count = 0;
	all->enter = 1;
	if (all->lst->select == 1)
		count++;
	tmp = all->lst->next;
	while (tmp != all->lst)
	{
		if (tmp->select == 1)
			count++;
		tmp = tmp->next;
	}
	all->ret_tab = (char **)malloc(sizeof(char *) * (count + 1));
	ft_stock_tab(all);
}
