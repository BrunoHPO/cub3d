/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:54:40 by bolegari          #+#    #+#             */
/*   Updated: 2025/07/28 15:04:39 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	safe_malloc(char **splits, int position, size_t buffer)
{
	int	i;

	i = 0;
	splits[position] = malloc(buffer);
	if (!splits[position])
	{
		while (i < position)
		{
			free(splits[i++]);
		}
		free(splits);
		return (1);
	}
	return (0);
}

static int	ft_fill(char **splits, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			s++;
			len++;
		}
		if (len)
		{
			if (safe_malloc(splits, i, len + 1))
				return (1);
			ft_strlcpy(splits[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

static int	ft_count_words(const char *s, char c)
{
	int		its_word;
	size_t	counter;

	counter = 0;
	while (*s)
	{
		its_word = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (!its_word)
			{
				counter++;
				its_word = 1;
			}
			s++;
		}
	}
	return (counter);
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	char	**splits;

	if (!s)
		return (NULL);
	words = 0;
	words = ft_count_words(s, c);
	splits = malloc((words + 1) * sizeof(char *));
	if (!splits)
		return (NULL);
	splits[words] = NULL;
	if (ft_fill(splits, s, c))
		return (NULL);
	return (splits);
}
