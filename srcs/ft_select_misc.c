/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 18:19:37 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/25 22:29:29 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	This function clear the terminal screen.
*/
void	ft_clear_screen(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_myputchar);
}

/*
**	ft_stock is called at the beginning of the program to stock the all
**	struct, and we need to call it in the signal functions because we need
**	to restablish the terminal and we can't put all in the signal functions
**	parameters.
*/
t_all	*ft_stock(t_all *all, int i)
{
	static t_all *tmp = NULL;

	if (i == 0)
		tmp = all;
	return (tmp);
}
