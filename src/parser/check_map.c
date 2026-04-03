/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 09:52:26 by bolegari          #+#    #+#             */
/*   Updated: 2026/03/14 09:52:26 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	flood_fill_external(char **grid, int y, int x, t_vars *vars)
{
	if (x < 0 || y < 0 || x >= vars->map.width || y >= vars->map.height)
		return ;
	if (grid[y][x] == WALL || grid[y][x] == 'W')
		return ;
	if (grid[y][x] == '0')
		print_error(vars, "Map not closed");
	grid[y][x] = 'W';
	flood_fill_external(grid, y, x - 1, vars);
	flood_fill_external(grid, y, x + 1, vars);
	flood_fill_external(grid, y - 1, x, vars);
	flood_fill_external(grid, y + 1, x, vars);
	return ;
}

static void	flood_fill_internal(char **grid, int y, int x, t_vars *vars)
{
	if (x < 0 || y < 0 || x >= vars->map.width || y >= vars->map.height)
		print_error(vars, "Map not closed");
	if (grid[y][x] == WALL || grid[y][x] == 'X')
		return ;
	if (grid[y][x] == ' ')
		print_error(vars, "Map not closed");
	grid[y][x] = 'X';
	flood_fill_internal(grid, y, x - 1, vars);
	flood_fill_internal(grid, y, x + 1, vars);
	flood_fill_internal(grid, y - 1, x, vars);
	flood_fill_internal(grid, y + 1, x, vars);
	return ;
}

static char	**copy_grid(t_vars *vars)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (vars->map.height + 1));
	if (!copy)
		print_error(vars, "Malloc failed");
	i = 0;
	while (i < vars->map.height)
	{
		copy[i] = ft_strdup(vars->map.grid[i]);
		if (!copy[i])
			print_error(vars, "Malloc failed");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	find_player(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map.height)
	{
		x = 0;
		while (x < vars->map.width)
		{
			if (ft_strchr("NSEW", vars->map.grid[y][x]))
			{
				vars->map.player_count++;
				vars->map.player_x = x;
				vars->map.player_y = y;
				vars->map.player_dir = vars->map.grid[y][x];
				vars->map.grid[y][x] = EMPTY;
			}
			x++;
		}
		y++;
	}
	if (vars->map.player_count != 1)
		print_error(vars, "Invalid number of players");
}

void	check_map(t_vars *vars)
{
	int		y;
	int		x;

	find_player(vars);
	vars->map.ff_grid = copy_grid(vars);
	flood_fill_internal(vars->map.ff_grid,
		vars->map.player_y, vars->map.player_x, vars);
	y = -1;
	while (++y < vars->map.height)
	{
		if (vars->map.ff_grid[y][0] == ' ')
			flood_fill_external(vars->map.ff_grid, y, 0, vars);
		if (vars->map.ff_grid[y][vars->map.width - 1] == ' ')
			flood_fill_external(vars->map.ff_grid, y,
				vars->map.width - 1, vars);
		x = 1;
		while (x < vars->map.width)
		{
			if (vars->map.ff_grid[y][x] == ' ')
				flood_fill_external(vars->map.ff_grid, y, x, vars);
			x++;
		}
	}
	free_char_array(vars->map.ff_grid);
	vars->map.ff_grid = NULL;
}
