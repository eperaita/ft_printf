/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:21:45 by eperaita          #+#    #+#             */
/*   Updated: 2021/08/06 13:18:10 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	char	*p;

	i = 0;
	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1);
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			break ;
	}
	while (end > i)
	{
		if (ft_strchr(set, s1[end - 1]))
			end--;
		else
			break ;
	}
	p = ft_substr(s1, i, end - i);
	return (p);
}
