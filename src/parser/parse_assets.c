/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:38:47 by bolegari          #+#    #+#             */
/*   Updated: 2026/03/05 10:38:47 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(char *line, char *chars)
{
	while (*line)
	{
		if (!ft_strchr(chars, *line))
			return (0);
		line++;
	}
	return (1);
}

static int	parse_texture(t_vars *vars, char **dest, char *value)
{
	while (*value == ' ' || *value == '\t')
		value++;
	if (*dest != NULL)
		print_error(vars, "Duplicate texture");
	*dest = trim_spaces(value);
	if (file_extension_checker(*dest, ".xpm"))
		print_error(vars, "Wrong texture file extension");
	return (1);
}

static int	parse_asset_line(t_vars *vars, char *line)
{
	int	res;

	res = 0;
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, NORTH_TX, 3) == 0)
		res = parse_texture(vars, &vars->map.tx_no, line + 3);
	else if (ft_strncmp(line, SOUTH_TX, 3) == 0)
		res = parse_texture(vars, &vars->map.tx_so, line + 3);
	else if (ft_strncmp(line, WEST_TX, 3) == 0)
		res = parse_texture(vars, &vars->map.tx_we, line + 3);
	else if (ft_strncmp(line, EAST_TX, 3) == 0)
		res = parse_texture(vars, &vars->map.tx_ea, line + 3);
	else if (ft_strncmp(line, CEIL_CL, 2) == 0)
		res = parse_colour(vars, &vars->map.cl_ceiling, line + 2);
	else if (ft_strncmp(line, FLOOR_CL, 2) == 0)
		res = parse_colour(vars, &vars->map.cl_floor, line + 2);
	return (res);
}

void	parse_assets(t_vars *vars)
{
	int	assets_found;

	assets_found = 0;
	vars->file.i = 0;
	while (vars->file.lines[vars->file.i])
	{
		if (line_content_checker(vars->file.lines[vars->file.i]))
		{
			vars->file.i++;
			continue ;
		}
		if (parse_asset_line(vars, vars->file.lines[vars->file.i]))
			assets_found++;
		else if (is_map_line(vars->file.lines[vars->file.i], "01NSEW "))
			break ;
		else
			print_error(vars, "Invalid asset");
		vars->file.i++;
	}
	if (assets_found != 6)
		print_error(vars, "Missing assets");
}
