/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:19 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/30 10:35:06 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>

int	ft_putchar(char c, int cont);

int	ft_putstr(char *str, int cont);

int	ft_putnbr(int nb, int cont);

int	ft_putnbr_u(unsigned int nb, int cont);

int	ft_putnbr_hexa(unsigned int nb, int cont, char d);

int	ft_putptr_hexa(unsigned long nb, int cont);

int	aux_bonus_func(char d, va_list args, int cont, char e);

int	bonus_func(char d, va_list args, int cont, char e);

int	conversion_bonus(char d, va_list args, int cont, char e);

int	check_bonus(char d, char e);

int	ft_printf(char const *format, ...);

int	ft_printf_bonus(char const *format, ...);

#endif
