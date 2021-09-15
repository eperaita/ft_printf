/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xxp_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:13:55 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/15 12:45:11 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

int	ft_itohexa(uintptr_t x, char *base)
{
	int		len;

	len = 0;
	if (x / 16 != 0)
		ft_itohexa(x / 16, base);
	ft_putchar_fd(base[x % 16], 1);
	while (x != 0)
	{
		x /= 16;
		len++;
	}
	return (len);
}

int	ft_printf_xxp(uintptr_t x, char type)
{
	char	*base;
	int		len;

	len = 0;
	if (type == 'p')
	{
		len += write (1, "0x", 2);
		if (x == 0)
			return (len += write (1, "0", 1));
		base = "0123456789abcdef";
		len = ft_itohexa(x, base) + 2;
	}
	if (x == 0)
		return (len += write(1, "0", 1));
	if (type == 'x')
	{
		base = "0123456789abcdef";
		len = ft_itohexa((unsigned int)x, base);
	}
	if (type == 'X')
	{
		base = "0123456789ABCDEF";
		len = ft_itohexa((unsigned int)x, base);
	}
	return (len);
}
