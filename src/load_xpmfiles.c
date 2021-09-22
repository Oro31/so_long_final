/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpmfiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:56:01 by rvalton           #+#    #+#             */
/*   Updated: 2021/09/17 20:56:03 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_xpm_image(t_vars *vars, t_data *data, char *str)
{
	int	w;
	int	h;

	data->img = mlx_xpm_file_to_image(vars->mlx, str, &w, &h);
	if (data->img == NULL)
		ft_exit(vars, 4);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ll,
			&data->e);
}

int	ft_load_xpmfiles(t_vars *vars)
{
	vars->xpm = 1;
	ft_new_xpm_image(vars, &vars->monde.space, "images/ground.XPM");
	ft_new_xpm_image(vars, &vars->monde.collect, "images/collectibles.XPM");
	ft_new_xpm_image(vars, &vars->monde.cdoor, "images/closeddoor.XPM");
	ft_new_xpm_image(vars, &vars->monde.odoor, "images/opendoor.XPM");
	ft_new_xpm_image(vars, &vars->ply.spr, "images/playeur.XPM");
	if (vars->monde.space.img == NULL || vars->monde.collect.img == NULL
		|| vars->monde.cdoor.img == NULL || vars->monde.odoor.img == NULL
		|| vars->ply.spr.img == NULL)
		return (0);
	return (1);
}
