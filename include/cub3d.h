/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 09:53:57 by bolegari          #+#    #+#             */
/*   Updated: 2026/03/15 20:37:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define _DEFAULT_SOURCE
#ifndef CUBE3D_H
# define CUBE3D_H
# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdint.h>
# include <fcntl.h>

# define EMPTY '0'
# define WALL '1'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

# define NORTH_TX "NO "
# define SOUTH_TX "SO "
# define WEST_TX "WE "
# define EAST_TX "EA "
# define CEIL_CL "C "
# define FLOOR_CL "F "

typedef struct s_file
{
	int		i;
	int		fd;
	int		count_lines;
	char	*path;
	char	**lines;
}	t_file;

typedef struct s_map
{
	char	*tx_no;
	char	*tx_so;
	char	*tx_we;
	char	*tx_ea;

	int		cl_floor;
	int		cl_ceiling;

	int		map_start_i;
	char	**grid;
	int		width;
	int		height;

	int		player_count;
	double	player_x;
	double	player_y;
	char	player_dir;
}	t_map;

typedef struct s_vars
{
	t_file		file;
	t_map		map;
}	t_vars;

void	print_error(t_vars *vars, char *s);
void	parse_file(t_vars *vars);
int		line_content_checker(char *str);
int		file_extension_checker(char *file, char *ext);
void	parse_assets(t_vars *vars);
int		is_map_line(char *line, char *chars);
int		parse_colour(t_vars *vars, int *dest, char *value);
void	handle_map(t_vars *vars);
void	check_map(t_vars *vars);
void	free_char_array(char **array);
void	parse_cleanup(t_vars *vars);
void	init_vars_file(t_vars *vars);
void	init_vars_map(t_vars *vars);
void	parse_debug(t_vars *vars);
char	*trim_spaces(char *str);
void	print_char_array(char **array);
#endif