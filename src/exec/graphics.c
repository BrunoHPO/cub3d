/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:17:09 by bnanque           #+#    #+#             */
/*   Updated: 2026/04/03 14:23:15 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(t_vars *vars)
{
	if (vars->tx_no.img_ptr)
		mlx_destroy_image(vars->mlx.ptr, vars->tx_no.img_ptr);
	if (vars->tx_so.img_ptr)
		mlx_destroy_image(vars->mlx.ptr, vars->tx_so.img_ptr);
	if (vars->tx_we.img_ptr)
		mlx_destroy_image(vars->mlx.ptr, vars->tx_we.img_ptr);
	if (vars->tx_ea.img_ptr)
		mlx_destroy_image(vars->mlx.ptr, vars->tx_ea.img_ptr);
	if (vars->mlx.canvas.img_ptr)
		mlx_destroy_image(vars->mlx.ptr, vars->mlx.canvas.img_ptr);
	if (vars->mlx.win)
		mlx_destroy_window(vars->mlx.ptr, vars->mlx.win);
	if (vars->mlx.ptr)
	{
		mlx_destroy_display(vars->mlx.ptr);
		free(vars->mlx.ptr);
	}
	parse_cleanup(vars);
	exit(0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	img->data[y * img->width + x] = color;
}

void	init_mlx_window(t_vars *vars)
{
	if (!vars->mlx.ptr)
		return ;
	vars->mlx.win = mlx_new_window(vars->mlx.ptr, WIN_W, WIN_H, "cub3D - 42");
	vars->mlx.canvas.img_ptr = mlx_new_image(vars->mlx.ptr, WIN_W, WIN_H);
	vars->mlx.canvas.data = (int *)mlx_get_data_addr(vars->mlx.canvas.img_ptr,
			&vars->mlx.canvas.bpp, &vars->mlx.canvas.line_len,
			&vars->mlx.canvas.endian);
	vars->mlx.canvas.width = WIN_W;
	vars->mlx.canvas.height = WIN_H;
}

int	load_texture(t_vars *vars, t_img *tex, char *path)
{
	int	w;
	int	h;

	if (!path)
		return (0);
	tex->img_ptr = mlx_xpm_file_to_image(vars->mlx.ptr, path, &w, &h);
	if (!tex->img_ptr)
	{
		printf("[cub3D] failed to load texture: %s\n", path);
		return (0);
	}
	tex->data = (int *)mlx_get_data_addr(tex->img_ptr, &tex->bpp,
			&tex->line_len, &tex->endian);
	tex->width = w;
	tex->height = h;
	if (vars->tex_w == 0 || vars->tex_h == 0)
	{
		vars->tex_w = w;
		vars->tex_h = h;
	}
	return (1);
}

int	load_textures(t_vars *vars)
{
	if (!load_texture(vars, &vars->tx_no, vars->map.tx_no))
		return (0);
	if (!load_texture(vars, &vars->tx_so, vars->map.tx_so))
		return (0);
	if (!load_texture(vars, &vars->tx_we, vars->map.tx_we))
		return (0);
	if (!load_texture(vars, &vars->tx_ea, vars->map.tx_ea))
		return (0);
	return (1);
}
