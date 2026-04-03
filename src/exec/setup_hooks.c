/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Codex <codex@openai.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:00:00 by Codex             #+#    #+#             */
/*   Updated: 2026/03/28 00:00:00 by Codex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_hooks(t_vars *vars)
{
	mlx_hook(vars->mlx.win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->mlx.win, 3, 1L << 1, key_release, vars);
	mlx_hook(vars->mlx.win, 17, 0, close_game, vars);
}
