/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 14:33:00 by bnanque           #+#    #+#             */
/*   Updated: 2026/03/28 00:00:00 by Codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_axis_dist(t_vars *vars, t_ray *ray, int axis)
{
	if (axis == 0 && ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (vars->map.player_x - ray->map_x) * ray->dlta_dist_x;
	}
	else if (axis == 0)
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - vars->map.player_x)
			* ray->dlta_dist_x;
	}
	else if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (vars->map.player_y - ray->map_y) * ray->dlta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - vars->map.player_y)
			* ray->dlta_dist_y;
	}
}

static void	init_ray(t_vars *vars, int x)
{
	t_ray	*ray;

	ray = &vars->ray;
	ray->camera_x = 2 * x / (double)WIN_W - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)vars->map.player_x;
	ray->map_y = (int)vars->map.player_y;
	ray->dlta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->dlta_dist_y = fabs(1 / ray->ray_dir_y);
	init_axis_dist(vars, ray, 0);
	init_axis_dist(vars, ray, 1);
}

static int	run_dda(t_vars *vars, int *wall_side)
{
	while (1)
	{
		if (vars->ray.side_dist_x < vars->ray.side_dist_y)
		{
			vars->ray.side_dist_x += vars->ray.dlta_dist_x;
			vars->ray.map_x += vars->ray.step_x;
			*wall_side = 0;
		}
		else
		{
			vars->ray.side_dist_y += vars->ray.dlta_dist_y;
			vars->ray.map_y += vars->ray.step_y;
			*wall_side = 1;
		}
		if (is_wall(vars, vars->ray.map_x, vars->ray.map_y))
			return (1);
	}
}

static void	calc_draw_limits(t_vars *vars, int wall_side, t_draw *draw)
{
	if (wall_side == 0)
		vars->ray.perp_wall_dist = (vars->ray.map_x - vars->map.player_x
				+ (1 - vars->ray.step_x) / 2.0) / vars->ray.ray_dir_x;
	else
		vars->ray.perp_wall_dist = (vars->ray.map_y - vars->map.player_y
				+ (1 - vars->ray.step_y) / 2.0) / vars->ray.ray_dir_y;
	if (vars->ray.perp_wall_dist < 0.0001)
		vars->ray.perp_wall_dist = 0.0001;
	draw->line_height = (int)(WIN_H / vars->ray.perp_wall_dist);
	draw->draw_start = -(draw->line_height) / 2 + WIN_H / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = draw->line_height / 2 + WIN_H / 2;
	if (draw->draw_end >= WIN_H)
		draw->draw_end = WIN_H - 1;
}

void	cast_rays(t_vars *vars)
{
	int		x;
	int		wall_side;
	t_draw	draw;

	x = 0;
	while (x < WIN_W)
	{
		init_ray(vars, x);
		run_dda(vars, &wall_side);
		calc_draw_limits(vars, wall_side, &draw);
		draw_ray_column(vars, x, wall_side, &draw);
		x++;
	}
}
