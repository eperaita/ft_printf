# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 15:35:46 by eperaita          #+#    #+#              #
#    Updated: 2021/09/15 12:35:34 by eperaita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c\
	  ft_printf_csdi.c\
	  ft_printf_xxp.c\
	  ft_printf_u.c


SRC_BONUS = ft_printf_bonus.c\
			ft_printf_csdi_bonus.c\
			ft_printf_xxp_bonus.c\
			ft_printf_u_bonus.c\
			ft_printf_bonus_utils.c\
			ft_printf_bonus_prints.c	

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

INCLUDES = ft_printf.h
INCLUDES_BONUS = ft_printf_bonus.h

CC = gcc 
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f


all: $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $(SRC) $(SRC_BONUS) 

$(NAME): $(OBJ) $(INCLUDES)
	$(MAKE) -C	libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ) 

bonus: $(OBJ_BONUS) $(INCLUDES_BONUS)
	$(MAKE) -C libft_bonus
	cp libft_bonus/libft_bonus.a .
	mv libft_bonus.a $(NAME)
	$(AR) $(NAME) $(OBJ_BONUS) 

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) libft.a


re: fclean all

.PHONY: all clean fclean re bonus
