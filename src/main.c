/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:46:41 by bolegari          #+#    #+#             */
/*   Updated: 2026/03/14 18:16:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(t_vars *vars, char *s)
{
	printf("Error\n");
	printf("%s\n", s);
	parse_cleanup(vars);
	exit(1);
}

static void	init_vars(t_vars *vars)
{
	init_vars_file(vars);
	init_vars_map(vars);
}

char	*trim_spaces(char *str)
{
	int		end;
	int		start;
	char	*res;

	end = ft_strlen(str) - 1;
	start = 0;
	while (start <= end && (str[start] == ' '
			|| str[start] == '\n' || str[start] == '\t'))
		start++;
	while (end >= start && (str[end] == ' '
			|| str[end] == '\n' || str[end] == '\t'))
		end--;
	res = ft_substr(str, start, end - start + 1);
	return (res);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		print_error(&vars, "Wrong Input, eg. ./cub3D <MAP_FILE.cub>");
	vars.file.path = trim_spaces(argv[1]);
	init_vars(&vars);
	parse_file(&vars);
	parse_assets(&vars);
	handle_map(&vars);
	check_map(&vars);
	parse_debug(&vars);
	parse_cleanup(&vars);
	return (0);
}
