/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:44:39 by bolegari          #+#    #+#             */
/*   Updated: 2025/08/06 09:44:09 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n, int base, char type)
{
	int		count;
	char	*symbols;

	if (type == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0)
	{
		write (1, "-", 1);
		return (print_digit(-n, base, type) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base, type);
		return (count + print_digit(n % base, base, type));
	}
	return (count);
}
