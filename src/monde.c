/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:00:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/09/17 21:00:49 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_set_rsl(int i, int j, t_rsl *rsl)
{
	rsl->w = i;
	rsl->h = j;
}

static void	ft_check_exit(t_map *monde, int j, int i)
{
	if (monde->posxe >= 0)
		monde->map[j][i] = '9';
	else if (monde->posxe == -1)
	{
		monde->posxe = i;
		monde->posye = j;
	}
}

static void	ft_check_player(t_vars *vars, t_map *monde, int j, int i)
{
	if (vars->ply.posx >= 0)
		monde->map[j][i] = '9';
	else if (vars->ply.posx == -1)
	{
		vars->ply.posx = i;
		vars->ply.posy = j;
	}	
}

static void	ft_check_assets(t_vars *vars, t_map *monde, t_rsl *rsl)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while (monde->map[++j])
	{
		i = -1;
		while (monde->map[j][++i])
		{
			if (monde->map[j][i] == 'C')
				monde->ncol++;
			else if (monde->map[j][i] == 'E')
				ft_check_exit(monde, j, i);
			else if (monde->map[j][i] == 'P')
				ft_check_player(vars, monde, j, i);
		}
	}
	ft_set_rsl(i, j, rsl);
}

int	ft_init_world(t_vars *vars, t_map *monde)
{
	t_rsl	rsl;

	ft_check_assets(vars, monde, &rsl);
	vars->rsl.w = rsl.w * 24;
	vars->rsl.h = rsl.h * 24;
	if (monde->ncol == 0 || monde->posxe < 0 || vars->ply.posx < 0)
		return (0);
	return (1);
}
