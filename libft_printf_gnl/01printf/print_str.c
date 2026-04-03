/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:44:03 by bolegari          #+#    #+#             */
/*   Updated: 2025/08/06 11:31:12 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (*str)
	{
		print_char((int) *str);
		++count;
		++str;
	}
	return (count);
}
