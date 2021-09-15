/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:13:30 by eperaita          #+#    #+#             */
/*   Updated: 2021/08/16 16:52:23 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	num_chars;

	i = 0;
	num_chars = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		num_chars = ft_strlen(s) - (size_t)start;
	if (len < num_chars)
		num_chars = len;
	p = (char *)malloc((num_chars + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (num_chars && start < ft_strlen(s))
	{
		p[i] = ((char *)s)[start + i];
		i++;
		num_chars--;
	}
	p[i] = '\0';
	return (p);
}
