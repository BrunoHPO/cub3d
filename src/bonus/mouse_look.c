/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_look.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:40:09 by bnanque           #+#    #+#             */
/*   Updated: 2026/03/24 09:18:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_move(int x, int y, t_vars *vars)
{
	int		dx;
	double	angle;

	(void)y;
	if (!vars->mouse_ready)
	{
		vars->mouse_last_x = x;
		vars->mouse_last_y = y;
		vars->mouse_ready = 1;
		return (0);
	}
	dx = x - vars->mouse_last_x;
	vars->mouse_last_x = x;
	vars->mouse_last_y = y;
	if (dx == 0)
		return (0);
	angle = (double)dx * MOUSE_SENSITIVITY;
	rotate(vars, angle);
	return (0);
}
