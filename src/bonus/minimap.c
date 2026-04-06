/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:53:43 by bnanque           #+#    #+#             */
/*   Updated: 2026/04/06 09:04:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_player_dir(t_vars *vars, int px, int py, int cell)
{
	int		i;
	int		steps;
	double	x;
	double	y;
	double	len;

	len = cell * 2.0;
	steps = (int)len;
	if (steps < 4)
		steps = 4;
	x = px;
	y = py;
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(&vars->mlx.canvas,
			(int)x, (int)y, MINIMAP_PLAYER_DIR);
		x += vars->ray.dir_x * (len / steps);
		y += vars->ray.dir_y * (len / steps);
		i++;
	}
}

static void	draw_rect(t_vars *vars, t_rect rect)
{
	int	x;
	int	y;

	y = 0;
	while (y < rect.h)
	{
		x = 0;
		while (x < rect.w)
		{
			my_mlx_pixel_put(&vars->mlx.canvas,
				rect.x + x, rect.y + y, rect.color);
			x++;
		}
		y++;
	}
}

static void	draw_map_cells(t_vars *vars, int cell, int mm_x, int mm_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map.height)
	{
		x = 0;
		while (x < vars->map.width)
		{
			if (vars->map.grid[y][x] == WALL)
				draw_rect(vars, (t_rect){mm_x + x * cell, mm_y + y * cell,
					cell, cell, MINIMAP_WALL});
			else if (vars->map.grid[y][x] != ' ')
				draw_rect(vars, (t_rect){mm_x + x * cell, mm_y + y * cell,
					cell, cell, MINIMAP_EMPTY});
			x++;
		}
		y++;
	}
}

static void	draw_player(t_vars *vars, int cell, int mm_x, int mm_y)
{
	int	px;
	int	py;

	px = (int)(mm_x + vars->map.player_x * cell);
	py = (int)(mm_y + vars->map.player_y * cell);
	draw_player_dir(vars, px, py, cell);
	draw_player_marker(vars, px, py, cell);
}

void	draw_minimap(t_vars *vars)
{
	int	cell;
	int	map_w;
	int	map_h;
	int	mm_x;
	int	mm_y;

	cell = minimap_cell_size(vars);
	if (cell == 0)
		return ;
	map_w = vars->map.width * cell;
	map_h = vars->map.height * cell;
	mm_x = MINIMAP_MARGIN;
	mm_y = MINIMAP_MARGIN;
	draw_rect(vars, (t_rect){mm_x - 2, mm_y - 2, map_w + 4,
		map_h + 4, MINIMAP_BORDER});
	draw_rect(vars, (t_rect){mm_x, mm_y, map_w, map_h, MINIMAP_BG});
	draw_map_cells(vars, cell, mm_x, mm_y);
	draw_player(vars, cell, mm_x, mm_y);
}
