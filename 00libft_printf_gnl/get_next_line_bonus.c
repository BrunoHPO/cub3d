/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:38:48 by bolegari          #+#    #+#             */
/*   Updated: 2025/10/15 11:31:22 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *big_buffer, char *small_buffer)
{
	char	*tmp;

	tmp = ft_strjoin(big_buffer, small_buffer);
	free(big_buffer);
	return (tmp);
}

static char	*set_leftovers(char *big_buffer)
{
	char	*next_line;
	size_t	i;

	i = 0;
	while (big_buffer[i] && big_buffer[i] != '\n')
		i++;
	if (!big_buffer[i])
	{
		free(big_buffer);
		return (NULL);
	}
	i++;
	next_line = ft_substr(big_buffer, i, ft_strlen(big_buffer) - i);
	if (!next_line)
		return (NULL);
	free(big_buffer);
	return (next_line);
}

static char	*set_line(char *big_buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	while (big_buffer[i] && big_buffer[i] != '\n')
		i++;
	if (big_buffer[i] == '\n')
		i++;
	line = ft_substr(big_buffer, 0, i);
	return (line);
}

static char	*read_file_buffer(int fd, char *big_buffer)
{
	char	*small_buffer;
	ssize_t	bytes_read;

	if (!big_buffer)
		big_buffer = ft_strdup("");
	small_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!small_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(big_buffer, '\n'))
	{
		bytes_read = read(fd, small_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(big_buffer);
			free(small_buffer);
			return (NULL);
		}
		small_buffer[bytes_read] = '\0';
		big_buffer = ft_join(big_buffer, small_buffer);
	}
	free (small_buffer);
	return (big_buffer);
}

char	*get_next_line(int fd)
{
	static char	*big_buffer[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	big_buffer[fd] = read_file_buffer(fd, big_buffer[fd]);
	if (!big_buffer[fd])
		return (NULL);
	if (!big_buffer[fd][0])
	{
		free(big_buffer[fd]);
		big_buffer[fd] = NULL;
		return (NULL);
	}
	line = set_line(big_buffer[fd]);
	big_buffer[fd] = set_leftovers(big_buffer[fd]);
	return (line);
}
