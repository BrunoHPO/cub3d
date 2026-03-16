/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:32:36 by bolegari          #+#    #+#             */
/*   Updated: 2025/08/07 14:56:40 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_ptr_digits(unsigned long long n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 16)
		return (print_char(symbols[n]));
	else
	{
		count = print_ptr_digits(n / 16);
		return (count + print_ptr_digits(n % 16));
	}
	return (count);
}

int	print_ptr(void *addr)
{
	int	count;

	count = 0;
	if (!addr)
		return (write (1, "(nil)", 5));
	count += print_str("0x");
	return (print_ptr_digits((unsigned long long) addr) + count);
}
