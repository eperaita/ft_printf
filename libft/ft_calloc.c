/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:17:09 by eperaita          #+#    #+#             */
/*   Updated: 2021/08/05 13:53:41 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc(num * size);
	if (!p)
		return (0);
	ft_bzero(p, num * size);
	return (p);
}
