/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csdi_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:11:56 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/15 12:46:02 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf_bonus.h"

int	ft_printf_s(char *str, t_flags *values)
{
	if (!str)
		return (write(1, "(null)", 6));
	if (values->prc > 0 && (unsigned long)values->prc <= ft_strlen(str))
		return (write(1, str, values->prc));
	return (write(1, str, ft_strlen(str)));
}

int	ft_printf_di(int dec)
{
	int		len;

	ft_putnbr_fd(dec, 1);
	if (dec == -2147483648)
		dec++;
	if (dec < 0)
		dec *= -1;
	len = ft_intlen(dec);
	return (len);
}
