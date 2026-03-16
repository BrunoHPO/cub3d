/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:36:32 by bolegari          #+#    #+#             */
/*   Updated: 2025/07/28 13:36:32 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (!fd)
		return ;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd (n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd (n / 10, fd);
			ft_putnbr_fd (n % 10, fd);
		}
		else
		{
			digit = n + 48;
			ft_putchar_fd(digit, fd);
		}
	}
}
