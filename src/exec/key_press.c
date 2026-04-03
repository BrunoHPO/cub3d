/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:21:10 by bnanque           #+#    #+#             */
/*   Updated: 2026/03/21 11:21:10 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		return (close_game(vars));
	if (keycode == 119)
		vars->keys[KEY_FORWARD] = 1;
	else if (keycode == 115)
		vars->keys[KEY_BACK] = 1;
	else if (keycode == 97)
		vars->keys[KEY_LEFT] = 1;
	else if (keycode == 100)
		vars->keys[KEY_RIGHT] = 1;
	else if (keycode == 65361)
		vars->keys[KEY_ROT_LEFT] = 1;
	else if (keycode == 65363)
		vars->keys[KEY_ROT_RIGHT] = 1;
	return (0);
}

void	free_map(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
