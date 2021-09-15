/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:37:15 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/15 12:48:45 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_is_neg(int nbr, t_flags *values)
{
	if (nbr < 0)
	{
		values->prc++;
		values->wi++;
	}
}

void	ft_countlen(t_flags *values, const char *src)
{
	va_list	sign;
	int		nbr;
	int		vlen;

	nbr = 0;
	va_copy(sign, values->ap);
	if (ft_strchr("c%", src[values->i]))
		vlen = 1;
	if (ft_strchr("di", src[values->i]))
		nbr = va_arg(sign, int);
	ft_is_neg(nbr, values);
	vlen = ft_intlen(nbr);
	if (ft_strchr("xX", src[values->i]))
		vlen = ft_hexlen(va_arg(sign, unsigned int));
	if (ft_strchr("p", src[values->i]))
		vlen = ft_plen(va_arg(sign, uintptr_t));
	if (ft_strchr("s", src[values->i]))
		vlen = ft_strlen(va_arg(sign, char *));
	if (ft_strchr("u", src[values->i]))
		vlen = ft_ulen(va_arg(sign, unsigned int));
	values->wi = values->wi - values->prc - vlen;
	if (!ft_strchr("s", src[values->i]))
		values->prc = values->prc - vlen;
	va_end(sign);
}

void	ft_countflaglen(t_flags *values, const char *src)
{
	va_list	sign;
	int		nbr;

	nbr = 0;
	va_copy(sign, values->ap);
	nbr = va_arg(sign, int);
	if (values->plus > 0 && nbr >= 0)
		values->wi--;
	if (values->space > 0 && src[values->i] != 's' && nbr >= 0)
		values->wi--;
	if (values->hastag > 0 && nbr != 0)
		values->wi -= 2;
	va_end(sign);
}
