/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:29:14 by bolegari          #+#    #+#             */
/*   Updated: 2025/10/14 16:14:14 by bolegari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n, int base, char type);
int	print_ptr(void *addr);
#endif
