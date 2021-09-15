/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csdi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:11:56 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/10 12:20:24 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf_s(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printf_di(int dec)
{
	char	*nbr;
	int		len;

	ft_putnbr_fd(dec, 1);
	nbr = ft_itoa(dec);
	len = ft_strlen(nbr);
	free (nbr);
	return (len);
}
