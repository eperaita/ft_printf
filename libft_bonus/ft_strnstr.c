/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:15:33 by eperaita          #+#    #+#             */
/*   Updated: 2021/08/12 10:26:42 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!to_find[0])
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (to_find[j] && (str[i + j] == to_find[j])
			&& str[i + j] && ((i + j) < n))
			j++;
		if (!to_find[j])
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
