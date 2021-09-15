/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:38:46 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/15 12:54:14 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_type(const char *src, t_flags *values, int *len)
{	
	int	off;

	off = 0;
	if (values->prc == 0 && src[values->i] == '.')
	{
		off = 1;
		values->i++;
	}
	ft_countlen(values, src);
	ft_countflaglen(values, src);
	if (!values->minus)
	{
		ft_printwspace(values, len);
		ft_printsign(src, values, len);
		ft_printprc(src, values, len);
	}
	else
		ft_printsign(src, values, len);
	ft_printvar(values, len, src, off);
	if (values->minus)
	{
		ft_printwspace(values, len);
		ft_printprc(src, values, len);
	}
}

void	ft_cflags(t_flags *values, const char *src)
{
	while (ft_strchr("+ -#0", src[++values->i]))
	{
		if (src[values->i] == '+')
			values->plus++;
		if (src[values->i] == ' ')
			values->space++;
		if (src[values->i] == '-')
			values->minus++;
		if (src[values->i] == '#')
			values->hastag++;
		if (src[values->i] == '0')
			values->zero++;
	}
	if (ft_isdigit(src[values->i]))
	{
		values->wi = ft_atoi(&src[values->i]);
		values->i += ft_intlen(values->wi);
	}
	if (ft_strchr(&src[values->i], '.') && ft_isdigit(src[values->i + 1]))
	{
		values->i++;
		values->prc = ft_atoi(&src[values->i]);
		values->i += ft_intlen(values->prc);
	}
}

void	ft_init(t_flags *values)
{
	values->wi = 0;
	values->prc = 0;
	values->plus = 0;
	values->minus = 0;
	values->hastag = 0;
	values->zero = 0;
	values->space = 0;
}

int	ft_printf(const char *src, ...)
{
	int		len;
	t_flags	*values;

	len = 0;
	values = malloc (sizeof(t_flags));
	if (!values || !src)
		return (0);
	va_start(values->ap, src);
	values->i = 0;
	while (src[values->i])
	{
		if (src[values->i] == '%' && src[values->i + 1])
		{
			ft_init(values);
			ft_cflags(values, src);
			ft_type(src, values, &len);
		}
		else
			len += ft_putchar_fd(src[values->i], 1);
		values->i++;
	}
	va_end(values->ap);
	free(values);
	return (len);
}
