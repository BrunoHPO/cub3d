/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:20:38 by bnanque           #+#    #+#             */
/*   Updated: 2026/03/24 00:35:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_north_south(t_vars *vars, char dir)
{
	vars->ray.dir_x = 0;
	vars->ray.plane_y = 0;
	if (dir == 'N')
	{
		vars->ray.dir_y = -1;
		vars->ray.plane_x = FOV_FACTOR;
	}
	else
	{
		vars->ray.dir_y = 1;
		vars->ray.plane_x = -FOV_FACTOR;
	}
}

static void	set_east_west(t_vars *vars, char dir)
{
	vars->ray.dir_y = 0;
	vars->ray.plane_x = 0;
	if (dir == 'E')
	{
		vars->ray.dir_x = 1;
		vars->ray.plane_y = FOV_FACTOR;
	}
	else
	{
		vars->ray.dir_x = -1;
		vars->ray.plane_y = -FOV_FACTOR;
	}
}

static void	set_dir_plane(t_vars *vars, char dir)
{
	if (dir == 'N' || dir == 'S')
		set_north_south(vars, dir);
	else if (dir == 'E' || dir == 'W')
		set_east_west(vars, dir);
}

void	init_player(t_vars *vars)
{
	vars->map.player_x += 0.5;
	vars->map.player_y += 0.5;
	set_dir_plane(vars, vars->map.player_dir);
}
