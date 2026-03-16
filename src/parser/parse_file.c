/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 09:53:32 by bolegari          #+#    #+#             */
/*   Updated: 2026/03/14 10:37:33 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	line_content_checker(char *str)
{
	while (str && *str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
			return (0);
		str++;
	}
	return (1);
}

int	file_extension_checker(char *file, char *ext)
{
	int	f_len;
	int	ext_len;

	f_len = ft_strlen(file);
	ext_len = ft_strlen(ext);
	if (f_len < ext_len)
		return (1);
	if (ft_strncmp(file + f_len - ext_len, ext, ext_len) == 0)
		return (0);
	return (1);
}

static void	file_dimension_checker(t_vars *vars)
{
	char	*buffer_line;
	int		empty_lines;

	empty_lines = 0;
	buffer_line = get_next_line(vars->file.fd);
	if (!buffer_line)
	{
		close(vars->file.fd);
		print_error(vars, "Empty file");
	}
	while (buffer_line)
	{
		vars->file.count_lines++;
		if (line_content_checker(buffer_line))
			empty_lines++;
		free(buffer_line);
		buffer_line = get_next_line(vars->file.fd);
	}
	free(buffer_line);
	if (empty_lines == vars->file.count_lines)
		print_error(vars, "No valid content at file");
}

static void	copy_content(t_vars *vars)
{
	char	*line;
	char	*trimmed;

	vars->file.lines = malloc(sizeof(char *) * (vars->file.count_lines + 1));
	if (!vars->file.lines)
		print_error(vars, "Malloc failed");
	line = get_next_line(vars->file.fd);
	while (line)
	{
		trimmed = ft_strtrim(line, "\n");
		free(line);
		vars->file.lines[vars->file.i] = trimmed;
		vars->file.i++;
		line = get_next_line(vars->file.fd);
	}
	vars->file.lines[vars->file.i] = NULL;
}

void	parse_file(t_vars *vars)
{
	if (file_extension_checker(vars->file.path, ".cub"))
		print_error(vars, "Wrong file extension");
	vars->file.fd = open(vars->file.path, O_RDONLY);
	if (vars->file.fd < 0)
		print_error(vars, "Failed to open file");
	file_dimension_checker(vars);
	close(vars->file.fd);
	vars->file.fd = open(vars->file.path, O_RDONLY);
	if (vars->file.fd < 0)
		print_error(vars, "Failed to open file");
	copy_content(vars);
	close(vars->file.fd);
}
