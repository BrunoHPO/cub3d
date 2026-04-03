/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:05:59 by bolegari          #+#    #+#             */
/*   Updated: 2025/07/28 13:05:59 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(long int nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			len;
	long int	nlong;

	nlong = n;
	len = ft_int_len(nlong);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (nlong == 0)
		res[0] = '0';
	if (nlong < 0)
	{
		res[0] = '-';
		nlong *= -1;
	}
	res[len] = '\0';
	while (nlong)
	{
		res[--len] = ((nlong % 10) + 48);
		nlong /= 10;
	}
	return (res);
}
