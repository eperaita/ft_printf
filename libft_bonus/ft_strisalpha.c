/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:57:49 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/13 13:10:50 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"
int	ft_strisalpha(char *a)
{
	int	i;

	i = 0;
	if (a == NULL)
		return (0);
	while (a[i])
	{
		if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] <= 'Z' && a[i] >= 'A'))
			return (1);
		i++;
	}
	return (0);
}	
