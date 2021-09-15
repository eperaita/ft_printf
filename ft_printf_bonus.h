/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:40:16 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/15 12:54:27 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft_bonus/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	va_list	ap;
	int		wi;
	int		prc;
	int		plus;
	int		minus;
	int		hastag;
	int		zero;
	int		space;
	int		i;
}	t_flags;

int		ft_printf(const char *src, ...);
int		ft_printf_s(char *str, t_flags *values);
int		ft_printf_di(int dec);
int		ft_printf_u(unsigned int u);
int		ft_printf_xxp(uintptr_t x, char type);
int		ft_itohexa(uintptr_t x, char *base);
int		len_unsigned(unsigned int u);
void	ft_init(t_flags *values);
void	ft_cflags(t_flags *values, const char *src);
void	ft_type(const char *src, t_flags *values, int *len);
void	ft_printvar(t_flags *values, int *len, const char *src, int off);
void	ft_printprc(const char *src, t_flags *values, int *len);
void	ft_printsign(const char *src, t_flags *values, int *len);
void	ft_printwspace(t_flags *values, int *len);
void	ft_countflaglen(t_flags *values, const char *src);
void	ft_countlen(t_flags *values, const char *src);
void	ft_is_neg(int nbr, t_flags *values);

#endif
