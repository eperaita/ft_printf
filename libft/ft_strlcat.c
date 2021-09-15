/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:12:56 by eperaita          #+#    #+#             */
/*   Updated: 2021/08/11 15:16:58 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	e;

	j = ft_strlen(src);
	i = ft_strlen(dest);
	if (size > i && size > 0)
	{
		e = i + j;
		size = size - i - 1;
		j = 0;
		while (src[j] != 0 && size != 0 )
		{
			dest[i++] = src[j++];
			size--;
		}
		dest[i] = '\0';
	}
	else
		e = size + j;
	return (e);
}
