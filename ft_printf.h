/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:40:16 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/10 12:24:19 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

int	ft_printf(const char *str, ...);

int	ft_printf_c(int c);
int	ft_printf_s(char *str);
int	ft_printf_di(int dec);
int	ft_printf_u(unsigned int u);
int	ft_printf_xxp(uintptr_t x, char type);

#endif
