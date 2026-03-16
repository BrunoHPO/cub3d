/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:25:19 by bolegari          #+#    #+#             */
/*   Updated: 2026/03/11 21:48:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_split(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
		i++;
	return (i);
}

int	parse_colour(t_vars *vars, int *dest, char *value)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;
	int		i;

	if (*dest != -1)
		print_error(vars, "Duplicate colour");
	rgb = ft_split(value, ',');
	if (!rgb || count_split(rgb) != 3)
		print_error(vars, "Invalid colour format");
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		print_error(vars, "Colour out of range");
	*dest = (r << 16) | (g << 8) | b;
	i = 0;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
	return (1);
}
