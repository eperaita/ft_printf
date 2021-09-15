/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:44:45 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/10 12:23:16 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	len_unsigned(unsigned int u)
{
	size_t	len;

	len = 0;
	while (u > 9)
	{
		u /= 10;
		len++;
	}
	len++;
	return ((int)len);
}

void	ft_putnbr_unsig(unsigned int u, int fd)
{
	if (u > 9)
		ft_putnbr_unsig(u / 10, fd);
	ft_putchar_fd(u % 10 + '0', fd);
}

int	ft_printf_u(unsigned int u)
{
	ft_putnbr_unsig(u, 1);
	return (len_unsigned(u));
}
