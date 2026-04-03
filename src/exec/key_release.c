/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnanque <bnanque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:21:32 by bnanque           #+#    #+#             */
/*   Updated: 2026/03/21 11:21:32 by bnanque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 119)
		vars->keys[KEY_FORWARD] = 0;
	else if (keycode == 115)
		vars->keys[KEY_BACK] = 0;
	else if (keycode == 97)
		vars->keys[KEY_LEFT] = 0;
	else if (keycode == 100)
		vars->keys[KEY_RIGHT] = 0;
	else if (keycode == 65361)
		vars->keys[KEY_ROT_LEFT] = 0;
	else if (keycode == 65363)
		vars->keys[KEY_ROT_RIGHT] = 0;
	return (0);
}
