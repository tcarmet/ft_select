/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 18:23:05 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/25 22:24:32 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	This function will in the first place collect the arguments given by
**	the user, then it will print the arguments and enter into a infinite
**	loop to keep the program on.
*/
int		ft_brain_select(char **argv, t_all *all)
{
	ft_clear_screen();
	ft_arg_to_list(argv, all);
	ft_count_col(all);
	ft_print_list_select(all);
	ft_check_size(all);
	ft_stock(all, 0);
	while (42)
	{
		if (!ft_keyhook(all))
			return (0);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_all			all;

	(void)argc;
	all.lst = NULL;
	ft_signal();
	if (!ft_init_termios(&all))
	{
		ft_putendl_fd("Initialization error, environnement must be correct", 2);
		return (-1);
	}
	if (argc >= 2)
		ft_brain_select(argv, &all);
	if (!ft_end_termios(&all))
		return (-1);
	return (0);
}
