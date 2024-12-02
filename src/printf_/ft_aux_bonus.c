/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:47:40 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/30 10:27:17 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	aux_bonus_func(char d, va_list args, int cont, char e)
{
	int	num;

	if (d == ' ' && (e == 'i' || e == 'd'))
	{
		num = va_arg(args, int);
		if (num > 0)
		{
			write(1, " ", 1);
			cont = cont + 1;
		}
		cont = ft_putnbr(num, cont);
	}
	return (cont);
}

int	bonus_func(char d, va_list args, int cont, char e)
{
	int	num;

	if (d == '#' && e == 'x')
	{
		cont = ft_putstr("0x", cont);
		cont = ft_putnbr_hexa(va_arg(args, unsigned int), cont, e);
	}
	else if (d == '#' && e == 'X')
	{
		cont = ft_putstr("0x", cont);
		cont = ft_putnbr_hexa(va_arg(args, unsigned int), cont, e);
	}
	else if (d == '+' && (e == 'i' || e == 'd'))
	{
		num = va_arg(args, int);
		if (num > 0)
		{
			write(1, "+", 1);
			cont = cont + 1;
		}
		cont = ft_putnbr(num, cont);
	}
	else
		cont = aux_bonus_func(d, args, cont, e);
	return (cont);
}

int	aux_conversion(unsigned long num, int cont)
{
	if (num > 0)
	{
		cont = ft_putstr("0x", cont);
	}
	cont = ft_putptr_hexa(num, cont);
	return (cont);
}

int	conversion_bonus(char d, va_list args, int cont, char e)
{
	if (d == 'c')
		cont = ft_putchar((char)va_arg(args, int), cont);
	else if (d == 's')
		cont = ft_putstr(va_arg(args, char *), cont);
	else if (d == 'd' || d == 'i')
		cont = ft_putnbr(va_arg(args, int), cont);
	else if (d == '%')
		cont = ft_putchar('%', cont);
	else if (d == 'u')
		cont = ft_putnbr_u(va_arg(args, unsigned int), cont);
	else if (d == 'x')
		cont = ft_putnbr_hexa(va_arg(args, unsigned int), cont, d);
	else if (d == 'X')
		cont = ft_putnbr_hexa(va_arg(args, unsigned int), cont, d);
	else if (d == 'p')
		cont = aux_conversion(va_arg(args, unsigned long), cont);
	else
	{
		cont = bonus_func(d, args, cont, e);
	}
	return (cont);
}

int	check_bonus(char d, char e)
{
	int	check;

	check = 0;
	if (d == '#' && (e == 'x' || e == 'X'))
		check = 1;
	else if (d == '+' && (e == 'i' || e == 'd'))
		check = 1;
	else if (d == ' ' && (e == 'i' || e == 'd'))
		check = 1;
	return (check);
}
