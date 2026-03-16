/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:23:06 by bolegari          #+#    #+#             */
/*   Updated: 2025/08/05 14:23:06 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(char type, va_list ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += print_char(va_arg(ap, int));
	else if (type == 's')
		count += print_str(va_arg(ap, char *));
	else if (type == 'p')
		count += print_ptr(va_arg(ap, void *));
	else if (type == 'd' || type == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10, type);
	else if (type == 'u')
		count += print_digit((long)(va_arg(ap, unsigned int)), 10, type);
	else if (type == 'x' || type == 'X')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16, type);
	else if (type == '%')
		count += print_char((int) type);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			count += check_type(*(++str), ap);
		else
			count += write(1, str, 1);
		++str;
	}
	va_end(ap);
	return (count);
}
