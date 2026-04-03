/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:22:22 by bnanque           #+#    #+#             */
/*   Updated: 2026/04/03 14:31:52 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_time_sec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + (tv.tv_usec / 1000000.0));
}

static void	update_delta_time(t_vars *vars)
{
	double	now;

	now = get_time_sec();
	if (vars->last_time == 0.0)
	{
		vars->delta_time = 0.0;
		vars->last_time = now;
		return ;
	}
	vars->delta_time = now - vars->last_time;
	if (vars->delta_time > 0.05)
		vars->delta_time = 0.05;
	vars->last_time = now;
}

static void	handle_input(t_vars *vars)
{
	double	speed;
	double	rot;

	speed = MOVE_SPEED * vars->delta_time;
	rot = ROT_SPEED * vars->delta_time;
	if (vars->keys[KEY_FORWARD])
		move_forward(vars, speed);
	if (vars->keys[KEY_BACK])
		move_backward(vars, speed);
	if (vars->keys[KEY_LEFT])
		strafe_left(vars, speed);
	if (vars->keys[KEY_RIGHT])
		strafe_right(vars, speed);
	if (vars->keys[KEY_ROT_LEFT])
		rotate(vars, -rot);
	if (vars->keys[KEY_ROT_RIGHT])
		rotate(vars, rot);
}

static void	draw_background(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (y < WIN_H / 2)
				my_mlx_pixel_put(&vars->mlx.canvas, x, y, vars->map.cl_ceiling);
			else
				my_mlx_pixel_put(&vars->mlx.canvas, x, y, vars->map.cl_floor);
			x++;
		}
		y++;
	}
}

int	render_frame(t_vars *vars)
{
	update_delta_time(vars);
	handle_input(vars);
	draw_background(vars);
	cast_rays(vars);
	draw_overlay(vars);
	mlx_put_image_to_window(vars->mlx.ptr, vars->mlx.win,
		vars->mlx.canvas.img_ptr, 0, 0);
	return (0);
}
