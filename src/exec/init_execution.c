/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:20:06 by bnanque           #+#    #+#             */
/*   Updated: 2026/03/28 12:04:25 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx(t_vars *vars)
{
	vars->mlx.ptr = mlx_init();
}

void	run_game(t_vars *vars)
{
	init_player(vars);
	init_mlx(vars);
	if (!load_textures(vars))
		close_game(vars);
	init_mlx_window(vars);
	setup_hooks(vars);
	mlx_loop_hook(vars->mlx.ptr, render_frame, vars);
	mlx_loop(vars->mlx.ptr);
}
