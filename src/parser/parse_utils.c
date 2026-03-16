/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:31:34 by bolegari          #+#    #+#             */
/*   Updated: 2026/03/14 09:41:32 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_textures(t_vars *vars)
{
	if (vars->map.tx_no)
		free(vars->map.tx_no);
	if (vars->map.tx_so)
		free(vars->map.tx_so);
	if (vars->map.tx_we)
		free(vars->map.tx_we);
	if (vars->map.tx_ea)
		free(vars->map.tx_ea);
}

void	free_char_array(char **array)
{
	char	**temp_ptr;

	if (array == NULL)
		return ;
	temp_ptr = array;
	while (*temp_ptr != NULL)
	{
		free(*temp_ptr);
		temp_ptr++;
	}
	free(array);
}

void	parse_cleanup(t_vars *vars)
{
	if (vars->file.path)
		free(vars->file.path);
	if (vars->file.lines)
		free_char_array(vars->file.lines);
	free_textures(vars);
	if (vars->map.grid)
		free_char_array(vars->map.grid);
}

void	init_vars_file(t_vars *vars)
{
	vars->file.i = 0;
	vars->file.count_lines = 0;
	vars->file.lines = NULL;
}

void	init_vars_map(t_vars *vars)
{
	vars->map.tx_no = NULL;
	vars->map.tx_so = NULL;
	vars->map.tx_we = NULL;
	vars->map.tx_ea = NULL;
	vars->map.cl_floor = -1;
	vars->map.cl_ceiling = -1;
	vars->map.grid = NULL;
	vars->map.width = 0;
	vars->map.height = 0;
	vars->map.player_count = 0;
	vars->map.player_x = 0;
	vars->map.player_y = 0;
	vars->map.player_dir = 'X';
}
