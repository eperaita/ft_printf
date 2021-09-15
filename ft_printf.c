/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:56:30 by eperaita          #+#    #+#             */
/*   Updated: 2021/08/30 10:45:18 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_typeof(char type, va_list args)
{
	unsigned int	len;

	len = 0;
	if (type == 'c')
		len = ft_printf_c(va_arg(args, int));
	if (type == 's')
		len = ft_printf_s(va_arg(args, char *));
	if (type == 'd' || type == 'i')
		len = ft_printf_di(va_arg(args, int));
	if (type == 'x' || type == 'X')
		len = ft_printf_xxp(va_arg(args, unsigned int), type);
	if (type == 'p')
		len = ft_printf_xxp(va_arg(args, uintptr_t), type);
	if (type == 'u')
		len = ft_printf_u(va_arg(args, unsigned int));
	if (type == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int				len;
	va_list			args;

	len = 0;
	va_start (args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_typeof(*str, args);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			len++;
		}
		str++;
	}
	va_end(args);
	return (len);
}
