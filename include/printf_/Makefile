# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: veragarc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 13:42:49 by veragarc          #+#    #+#              #
#    Updated: 2024/10/01 13:42:58 by veragarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_aux_printf.c \
		ft_aux_hexa.c \
		ft_printf.c
SRC_B = ft_aux_printf.c \
		ft_aux_hexa.c \
		ft_aux_bonus.c \
		ft_printf_bonus.c
OBJT = $(SRC:.c=.o)
OBJT_B = $(SRC_B:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJT)
		ar rc $(NAME) $(OBJT)

bonus:		$(OBJT_B)
		ar rc $(NAME) $(OBJT_B)

clean:
		-rm -f $(OBJT) $(OBJT_B)

%.o: %.c
		cc -Wall -Wextra -Werror -c $< -o $@

fclean: 	clean
		-rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus
