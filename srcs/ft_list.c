/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 15:47:47 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/25 22:22:55 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	This function will initialize the current position of the linked list.
*/
t_lst	*ft_init_lst(void)
{
	t_lst	*tmp;

	tmp = (t_lst *)malloc(sizeof(t_lst));
	tmp->value = NULL;
	tmp->select = 0;
	tmp->line = 0;
	tmp->len = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

/*
**	This function create a new link to the linked list,
**	and put the string into the list.
*/
t_lst	*ft_fill_list(char *str)
{
	t_lst	*tmp;

	tmp = ft_init_lst();
	tmp->value = ft_strdup(str);
	tmp->len = ft_strlen(tmp->value);
	return (tmp);
}

/*
**	This function gets the link and put it into the list.
*/
void	ft_push_list(t_all *all, t_lst *lst)
{
	t_lst	*tmp;

	if (all->lst == NULL)
	{
		lst->prev = lst;
		lst->next = lst;
		all->lst = lst;
		lst->line = 1;
	}
	else
	{
		tmp = all->lst->prev;
		tmp->next = lst;
		lst->next = all->lst;
		lst->prev = tmp;
		all->lst->prev = lst;
	}
}

/*
**	This function will collect the string and put it into the linked list.
*/
void	ft_arg_to_list(char **argv, t_all *all)
{
	int		i;
	t_lst	*tmp;

	i = 1;
	while (argv[i])
	{
		tmp = ft_fill_list(argv[i]);
		ft_push_list(all, tmp);
		i++;
	}
	all->count[LINE] = i;
}
