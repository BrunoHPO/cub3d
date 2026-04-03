/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:29:46 by bolegari          #+#    #+#             */
/*   Updated: 2025/07/21 17:32:41 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t len)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *) dest;
	while (len > 0)
	{
		*(tmp_ptr++) = 0;
		len--;
	}
}
