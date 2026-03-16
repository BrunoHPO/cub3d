/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:11:40 by marvin            #+#    #+#             */
/*   Updated: 2026/03/13 18:11:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("[%d]\t%s\n", i, array[i]);
		i++;
	}
}

static void	print_file(t_file *file)
{
	printf("path: %s\n", file->path);
}

static void	print_map(t_map *map)
{
	printf("NO: %s\n", map->tx_no);
	printf("SO: %s\n", map->tx_so);
	printf("WE: %s\n", map->tx_we);
	printf("EA: %s\n", map->tx_ea);
	printf("Floor: %d\n", map->cl_floor);
	printf("Ceiling: %d\n", map->cl_ceiling);
	printf("map_start_i: %d\n", map->map_start_i);
	printf("width: %d\n", map->width);
	printf("height: %d\n", map->height);
	printf("player_count: %d\n", map->player_count);
	printf("player_x: %f\n", map->player_x);
	printf("player_y: %f\n", map->player_y);
	printf("player_dir: %c\n", map->player_dir);
	if (map->grid)
		print_char_array(map->grid);
}

void	parse_debug(t_vars *vars)
{
	printf("=========== PARSER VARS ===========\n");
	print_file(&vars->file);
	print_map(&vars->map);
	printf("==================================\n");
}
