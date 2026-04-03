/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:32:50 by bolegari          #+#    #+#             */
/*   Updated: 2025/07/28 13:32:50 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*strmod;

	strmod = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!strmod)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		strmod[i] = (*f)(i, s[i]);
		i++;
	}
	strmod[i] = '\0';
	return (strmod);
}
