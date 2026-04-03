/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:57:59 by bnanque           #+#    #+#             */
/*   Updated: 2026/03/28 11:57:59 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	clamp_int(int v, int lo, int hi)
{
	if (v < lo)
		return (lo);
	if (v > hi)
		return (hi);
	return (v);
}

int	minimap_cell_size(t_vars *vars)
{
	int	max_dim;
	int	cell;

	max_dim = max_int(vars->map.width, vars->map.height);
	if (max_dim <= 0)
		return (0);
	cell = MINIMAP_MAX_SIZE / max_dim;
	cell = clamp_int(cell, MINIMAP_CELL_MIN, MINIMAP_CELL_MAX);
	return (cell);
}

void	draw_player_marker(t_vars *vars, int px, int py, int cell)
{
	int	r;
	int	x;
	int	y;

	r = clamp_int(cell / 4, 2, 6);
	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				my_mlx_pixel_put(&vars->mlx.canvas,
					px + x, py + y, MINIMAP_PLAYER);
			x++;
		}
		y++;
	}
}
