/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_prints.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:52:09 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/15 13:02:31 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_printprc(const char *src, t_flags *values, int *len)
{
	while (values->wi > 0 && values->zero > 0 && values->prc < 1)
	{
		*len += ft_putchar_fd('0', 1);
		values->wi--;
	}
	while (values->prc > 0 && !ft_strchr("sc", src[values->i]))
	{
		*len += ft_putchar_fd('0', 1);
		values->prc--;
	}
}

void	ft_printwspace(t_flags *values, int *len)
{
	while (values->wi > 0 && values->zero < 1)
	{
		*len += ft_putchar_fd(' ', 1);
		values->wi--;
	}
	while (values->wi > 0 && values->zero > 0 && values->prc > 0)
	{
		*len += ft_putchar_fd(' ', 1);
		values->wi--;
	}
}

void	ft_printsign(const char *src, t_flags *values, int *len)
{
	va_list	sign;
	int		nbr;

	nbr = 0;
	va_copy(sign, values->ap);
	nbr = va_arg(sign, int);
	if (src[values->i] == '%')
		return ;
	if (nbr < 0 && !ft_strchr("cpuxX", src[values->i]))
		*len += ft_putchar_fd('-', 1);
	if (values->plus > 0 && nbr >= 0)
		*len += ft_putchar_fd('+', 1);
	if (values->space > 0 && nbr >= 0 && src[values->i] != 's')
		*len += ft_putchar_fd(' ', 1);
	if (values->hastag > 0 && nbr != 0 && src[values->i] == 'x')
		*len += ft_putstr_fd("0x", 1);
	if (values->hastag > 0 && nbr != 0 && src[values->i] == 'X')
		*len += ft_putstr_fd("0X", 1);
	va_end(sign);
}

void	ft_printvar(t_flags *values, int *len, const char *src, int off)
{
	if (src[values->i] == 'c')
		*len += ft_putchar_fd(va_arg(values->ap, int), 1);
	if (src[values->i] == 's' && !off)
		*len += ft_printf_s(va_arg(values->ap, char *), values);
	if (src[values->i] == 'd' || src[values->i] == 'i')
		*len += ft_printf_di(va_arg(values->ap, int));
	if (src[values->i] == 'x' || src[values->i] == 'X')
		*len += ft_printf_xxp(va_arg(values->ap, unsigned int), src[values->i]);
	if (src[values->i] == 'p')
		*len += ft_printf_xxp(va_arg(values->ap, uintptr_t), src[values->i]);
	if (src[values->i] == 'u')
		*len += ft_printf_u(va_arg(values->ap, unsigned int));
	if (src[values->i] == '%')
		*len += write(1, "%", 1);
}
