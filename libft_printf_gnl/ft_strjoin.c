/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:32:44 by bolegari          #+#    #+#             */
/*   Updated: 2025/07/30 17:55:15 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strj;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	strj = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!strj)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		strj[j++] = s1[i++];
	i = 0;
	while (s2[i])
		strj[j++] = s2[i++];
	strj[j] = '\0';
	return (strj);
}
