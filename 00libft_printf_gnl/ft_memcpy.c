/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:36:17 by bolegari          #+#    #+#             */
/*   Updated: 2025/07/21 18:24:05 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (src == NULL && dest == NULL)
		return (dest);
	tmp_dest = (unsigned char *) dest;
	tmp_src = (unsigned char *) src;
	while (len > 0)
	{
		*(tmp_dest++) = *(tmp_src++);
		len--;
	}
	return (dest);
}
