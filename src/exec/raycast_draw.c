/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 14:33:00 by bnanque           #+#    #+#             */
/*   Updated: 2026/03/28 12:09:30 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*select_wall_texture(t_vars *vars, int side)
{
	if (side == 0)
	{
		if (vars->ray.ray_dir_x > 0)
			return (&vars->tx_ea);
		return (&vars->tx_we);
	}
	if (vars->ray.ray_dir_y > 0)
		return (&vars->tx_so);
	return (&vars->tx_no);
}

static int	calc_tex_x(t_vars *vars, t_img *tex, int side)
{
	double	wall_x;
	int		tex_w;
	int		tex_x;

	if (side == 0)
		wall_x = vars->map.player_y + vars->ray.perp_wall_dist
			* vars->ray.ray_dir_y;
	else
		wall_x = vars->map.player_x + vars->ray.perp_wall_dist
			* vars->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	if (tex && tex->width > 0)
		tex_w = tex->width;
	else
		tex_w = vars->tex_w;
	tex_x = (int)(wall_x * tex_w);
	if (side == 0 && vars->ray.ray_dir_x > 0)
		tex_x = tex_w - tex_x - 1;
	if (side == 1 && vars->ray.ray_dir_y < 0)
		tex_x = tex_w - tex_x - 1;
	return (tex_x);
}

static int	sample_color(t_img *tex, int tex_x, int tex_y, int side)
{
	int	color;

	if (tex && tex->data)
	{
		color = tex->data[tex_y * tex->width + tex_x];
		if (side == 1)
			color = (color >> 1) & 0x7F7F7F;
		return (color);
	}
	if (side == 1)
		return (0x555555);
	return (0xAAAAAA);
}

static int	get_tex_y(int y, t_draw *draw)
{
	int	tex_pos;
	int	tex_y;

	tex_pos = y * 256 - WIN_H * 128 + draw->line_height * 128;
	tex_y = ((tex_pos * draw->tex_h) / draw->line_height) / 256;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= draw->tex_h)
		tex_y = draw->tex_h - 1;
	return (tex_y);
}

void	draw_ray_column(t_vars *vars, int x, int side, t_draw *draw)
{
	t_img	*tex;
	int		y;

	tex = select_wall_texture(vars, side);
	if (tex && tex->height > 0)
		draw->tex_h = tex->height;
	else
		draw->tex_h = vars->tex_h;
	draw->tex_x = calc_tex_x(vars, tex, side);
	y = draw->draw_start;
	while (y <= draw->draw_end)
	{
		my_mlx_pixel_put(&vars->mlx.canvas, x, y,
			sample_color(tex, draw->tex_x, get_tex_y(y, draw), side));
		y++;
	}
}
