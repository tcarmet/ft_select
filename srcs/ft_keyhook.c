/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 18:58:30 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/25 22:22:21 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_simple_key(t_all *all, char *buffer[5])
{
	if (BUFFER == DOWN_KEY)
		ft_move_down(all);
	if (BUFFER == UP_KEY)
		ft_move_up(all);
	if (BUFFER == SPACE_KEY)
		ft_space_key(all);
	if (BUFFER == HOME_KEY)
		ft_goto_begin(all);
	if (BUFFER == END_KEY)
		ft_goto_end(all);
	if (BUFFER == CRTL_A_KEY)
		ft_select_all(all);
	if (BUFFER == TAB_KEY)
		ft_tab_key(all);
}

/*
**	This function collect the keyboard keys, and call the right function
**	for the specified key.
*/
int			ft_keyhook(t_all *all)
{
	char	*buffer[5];

	ft_bzero(buffer, 5);
	read(0, buffer, 4);
	if (BUFFER == ESC_KEY)
		return (0);
	if (ft_check_size(all))
	{
		ft_simple_key(all, buffer);
		if (BUFFER == DEL_KEY || BUFFER == SUP_KEY)
		{
			if (!ft_delete(all))
				return (0);
		}
		if (BUFFER == RET_KEY)
		{
			ft_return_key(all);
			return (0);
		}
		ft_clear_screen();
		ft_print_list_select(all);
	}
	return (1);
}
