/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 09:53:57 by bolegari          #+#    #+#             */
/*   Updated: 2026/04/03 14:34:09 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define _DEFAULT_SOURCE

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EMPTY '0'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'
# define WALL '1'

# define NORTH_TX "NO "
# define SOUTH_TX "SO "
# define WEST_TX "WE "
# define EAST_TX "EA "
# define CEIL_CL "C "
# define FLOOR_CL "F "

# define KEY_FORWARD 0
# define KEY_BACK 1
# define KEY_LEFT 2
# define KEY_RIGHT 3
# define KEY_ROT_LEFT 4
# define KEY_ROT_RIGHT 5

# define WIN_W 1900
# define WIN_H 1000
# define PLAYER_RADIUS 0.20
# define MOVE_SPEED 1.0
# define ROT_SPEED 1.5
# define MAX_DELTA_TIME 0.20
# define FOV_FACTOR 0.66
# define MOUSE_SENSITIVITY 0.0030

/* Bonus: minimap */
# define MINIMAP_MAX_SIZE 500
# define MINIMAP_CELL_MIN 2
# define MINIMAP_CELL_MAX 12
# define MINIMAP_MARGIN 12
# define MINIMAP_BG 0x000000
# define MINIMAP_BORDER 0x444444
# define MINIMAP_WALL 0xFFFFFF
# define MINIMAP_EMPTY 0x333333
# define MINIMAP_PLAYER 0x00FF00
# define MINIMAP_PLAYER_DIR 0x00AA00

typedef struct s_file
{
	int			i;
	int			fd;
	int			count_lines;
	char		*path;
	char		**lines;
}	t_file;

typedef struct s_map
{
	char		*tx_no;
	char		*tx_so;
	char		*tx_we;
	char		*tx_ea;
	int			cl_floor;
	int			cl_ceiling;
	int			map_start_i;
	char		**grid;
	int			width;
	int			height;
	int			player_count;
	double		player_x;
	double		player_y;
	char		player_dir;
}	t_map;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			width;
	int			height;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	t_img		canvas;
}	t_mlx;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		dlta_dist_x;
	double		dlta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
}	t_ray;

typedef struct s_draw
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_h;
	int			tex_x;
}	t_draw;

typedef struct s_vars
{
	t_file		file;
	t_map		map;
	t_img		tx_no;
	t_img		tx_so;
	t_img		tx_we;
	t_img		tx_ea;
	int			tex_w;
	int			tex_h;
	t_mlx		mlx;
	t_ray		ray;
	int			keys[6];
	double		last_time;
	double		delta_time;
	int			mouse_ready;
	int			mouse_last_x;
	int			mouse_last_y;
}	t_vars;

int				close_game(t_vars *vars);
void			free_map(char **grid);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			init_mlx_window(t_vars *vars);
void			setup_hooks(t_vars *vars);
void			draw_minimap(t_vars *vars);
void			draw_player_marker(t_vars *vars, int px, int py, int cell);
int				minimap_cell_size(t_vars *vars);	
int				load_texture(t_vars *vars, t_img *tex, char *path);
int				load_textures(t_vars *vars);
void			run_game(t_vars *vars);
void			init_player(t_vars *vars);
int				key_press(int keycode, t_vars *vars);
int				key_release(int keycode, t_vars *vars);
int				render_frame(t_vars *vars);
void			strafe_left(t_vars *vars, double speed);
void			strafe_right(t_vars *vars, double speed);
void			rotate(t_vars *vars, double angle);
void			draw_overlay(t_vars *vars);
int				is_wall(t_vars *vars, int x, int y);
int				can_move(t_vars *vars, double x, double y);

void			move_forward(t_vars *vars, double speed);
void			move_backward(t_vars *vars, double speed);
int				mouse_move(int x, int y, t_vars *vars);
void			cast_rays(t_vars *vars);
void			draw_ray_column(t_vars *vars, int x, int side, t_draw *draw);
void			print_error(t_vars *vars, char *s);
void			parse_file(t_vars *vars);
int				line_content_checker(char *str);
int				file_extension_checker(char *file, char *ext);
void			parse_assets(t_vars *vars);
int				is_map_line(char *line, char *chars);
int				parse_colour(t_vars *vars, int *dest, char *value);
void			handle_map(t_vars *vars);
void			check_map(t_vars *vars);
void			free_char_array(char **array);
void			parse_cleanup(t_vars *vars);
void			init_vars_file(t_vars *vars);
void			init_vars_map(t_vars *vars);
void			parse_debug(t_vars *vars);
char			*trim_spaces(char *str);
void			print_char_array(char **array);

#endif
