/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:02:00 by bnanque           #+#    #+#             */
/*   Updated: 2026/03/28 00:00:00 by Codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_vars *vars, int x, int y)
{
	if (x < 0 || y < 0 || x >= vars->map.width || y >= vars->map.height)
		return (1);
	if (vars->map.grid[y][x] == WALL || vars->map.grid[y][x] == ' ')
		return (1);
	return (0);
}

int	can_move(t_vars *vars, double x, double y)
{
	double	r;

	r = PLAYER_RADIUS;
	if (is_wall(vars, (int)(x - r), (int)(y - r)))
		return (0);
	if (is_wall(vars, (int)(x + r), (int)(y - r)))
		return (0);
	if (is_wall(vars, (int)(x - r), (int)(y + r)))
		return (0);
	if (is_wall(vars, (int)(x + r), (int)(y + r)))
		return (0);
	return (1);
}

void	move_forward(t_vars *vars, double speed)
{
	double	nx;
	double	ny;

	nx = vars->map.player_x + vars->ray.dir_x * speed;
	ny = vars->map.player_y + vars->ray.dir_y * speed;
	if (can_move(vars, nx, vars->map.player_y))
		vars->map.player_x = nx;
	if (can_move(vars, vars->map.player_x, ny))
		vars->map.player_y = ny;
}

void	move_backward(t_vars *vars, double speed)
{
	double	nx;
	double	ny;

	nx = vars->map.player_x - vars->ray.dir_x * speed;
	ny = vars->map.player_y - vars->ray.dir_y * speed;
	if (can_move(vars, nx, vars->map.player_y))
		vars->map.player_x = nx;
	if (can_move(vars, vars->map.player_x, ny))
		vars->map.player_y = ny;
}
