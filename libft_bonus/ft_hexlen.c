/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:56:22 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/13 16:45:17 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"
#include	<stdio.h>
int	ft_hexlen(unsigned int i)
{
	int	len;

	len = 0;

	if (!i)
		return (1);
	while (i > 0)
	{
		i /= 16;
		len++;
	}
	return (len);
}
int	ft_plen(uintptr_t i)
{
	int		len;

	len = 2;
	if (!i)
		return (3);
	while (i != 0)
	{
		i /= 16;
		len++;
	}
	return (len);
}
