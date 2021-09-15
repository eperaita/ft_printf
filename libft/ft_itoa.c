/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:16:51 by eperaita          #+#    #+#             */
/*   Updated: 2021/08/30 11:06:41 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_fill_char(char *buff, size_t len, long n, size_t neg)
{
	buff[len + neg] = '\0';
	while (len)
	{
		len--;
		buff[len + neg] = n % 10 + '0';
		n /= 10;
	}
	if (neg == 1)
		buff[0] = '-';
	return (buff);
}

size_t	len_int(long n, size_t len)
{
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char		*buff;
	size_t		len;
	size_t		neg;
	long		nb;

	neg = 0;
	len = 0;
	nb = (long)n;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	len = len_int(nb, len);
	buff = malloc((len + 1 + neg) * sizeof(char));
	if (!buff)
		return (0);
	buff = ft_fill_char(buff, len, nb, neg);
	return (buff);
}
