/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myputchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 15:24:36 by tcarmet           #+#    #+#             */
/*   Updated: 2015/03/25 22:23:24 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	This putchar was created to work as the original with tputs,
**	And the output was changed because we can't print on the main output.
*/
int		ft_myputchar(int c)
{
	return (write(2, &c, 1));
}
