/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:50:30 by rvalton           #+#    #+#             */
/*   Updated: 2021/09/17 20:54:24 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error_bis(int e)
{
	if (e == 1)
		perror("Initialisation before parsing failed");
	else if (e == 2)
		perror("Opening file failed");
	else if (e == 3 || e ==5)
	{
		ft_putstr("Map is not playable: Map must have ");
		ft_putstr("1 exit (E), 1 starting position (P) and");
		ft_putstr(" at least 1 collectible (C); ");
		ft_putstr("furthermore, Map can only be comosed ");
		ft_putstr("of 5 possibles characters : 0 (empty ");
		ft_putstr("space), 1 (walls), C (collectible), E (map ");
		ft_putstr("exit) and P (player starting position)\n");
	}
	else if (e == 4)
		perror("Loading xpm files failed");
}

void	ft_error(int e)
{
	ft_putstr("Error\n");
	if (e <= 5 && e >= 1)
		ft_error_bis(e);
	else if (e == 6 || e == 7)
		ft_putstr("Map is not rectangular or not surrounded by walls\n");
	else if (e == 8)
		ft_putstr("Not enought argument\n");
	else if (e == 9)
	{
		ft_putstr("Map file's name is not correct ");
		ft_putstr("(must be a .ber file)\n");
	}
}
