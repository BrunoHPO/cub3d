/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_strafe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:21:52 by bnanque           #+#    #+#             */
/*   Updated: 2026/03/28 00:00:00 by Codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	strafe_left(t_vars *vars, double speed)
{
	double	nx;
	double	ny;

	nx = vars->map.player_x - vars->ray.plane_x * speed;
	ny = vars->map.player_y - vars->ray.plane_y * speed;
	if (can_move(vars, nx, vars->map.player_y))
		vars->map.player_x = nx;
	if (can_move(vars, vars->map.player_x, ny))
		vars->map.player_y = ny;
}

void	strafe_right(t_vars *vars, double speed)
{
	double	nx;
	double	ny;

	nx = vars->map.player_x + vars->ray.plane_x * speed;
	ny = vars->map.player_y + vars->ray.plane_y * speed;
	if (can_move(vars, nx, vars->map.player_y))
		vars->map.player_x = nx;
	if (can_move(vars, vars->map.player_x, ny))
		vars->map.player_y = ny;
}

void	rotate(t_vars *vars, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->ray.dir_x;
	old_plane_x = vars->ray.plane_x;
	vars->ray.dir_x = vars->ray.dir_x * cos(angle)
		- vars->ray.dir_y * sin(angle);
	vars->ray.dir_y = old_dir_x * sin(angle)
		+ vars->ray.dir_y * cos(angle);
	vars->ray.plane_x = vars->ray.plane_x * cos(angle)
		- vars->ray.plane_y * sin(angle);
	vars->ray.plane_y = old_plane_x * sin(angle)
		+ vars->ray.plane_y * cos(angle);
}
