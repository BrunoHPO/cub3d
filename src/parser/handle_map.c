/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 09:52:39 by bolegari          #+#    #+#             */
/*   Updated: 2026/03/14 09:52:40 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_grid(t_vars *vars)
{
	int	x;
	int	y;
	int	map_start_i;

	y = 0;
	map_start_i = vars->map.map_start_i;
	while (y < vars->map.height)
	{
		x = 0;
		while (vars->file.lines[map_start_i][x] && x < vars->map.width)
		{
			vars->map.grid[y][x] = vars->file.lines[map_start_i][x];
			x++;
		}
		map_start_i++;
		y++;
	}
}

static void	create_grid(t_vars *vars)
{
	vars->map.grid = malloc(sizeof(char *) * (vars->map.height + 1));
	if (!vars->map.grid)
		print_error(vars, "Malloc failed");
	vars->file.i = 0;
	while (vars->file.i < vars->map.height)
	{
		vars->map.grid[vars->file.i] = malloc(vars->map.width + 1);
		if (!vars->map.grid[vars->file.i])
			print_error(vars, "Malloc failed");
		ft_memset(vars->map.grid[vars->file.i], ' ', vars->map.width);
		vars->map.grid[vars->file.i][vars->map.width] = '\0';
		vars->file.i++;
	}
	vars->map.grid[vars->map.height] = NULL;
}

static void	parse_map(t_vars *vars)
{
	int		len;

	vars->map.map_start_i = vars->file.i;
	while (vars->file.lines[vars->file.i])
	{
		if (line_content_checker(vars->file.lines[vars->file.i]))
			print_error(vars, "It is not allowed empty line");
		if (!is_map_line(vars->file.lines[vars->file.i], "01NSEW "))
			print_error(vars, "Map must contain these chars: 0,1,N,S,E,W");
		len = ft_strlen(vars->file.lines[vars->file.i]);
		if (len > vars->map.width)
			vars->map.width = len;
		vars->file.i++;
	}
	vars->map.height = vars->file.i - vars->map.map_start_i;
}

void	handle_map(t_vars *vars)
{
	parse_map(vars);
	create_grid(vars);
	fill_grid(vars);
}
