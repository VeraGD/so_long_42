/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:47:29 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/30 10:28:37 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "ft_printf.h"

int	ft_printf_bonus(char const *format, ...)
{
	va_list	args;
	int		cont;
	int		i;

	va_start(args, format);
	i = 0;
	cont = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
			cont++;
		}
		else
		{
			i++;
			cont = conversion_bonus(format[i], args, cont, format[i + 1]);
			if (check_bonus(format[i], format[i + 1]) == 1)
				i++;
			i++;
		}
	}
	return (cont);
}

// int main(void)
// {
//     //int i = 2;
//     //int *puntero ;
//     //puntero = &i;
//     //int j = ft_printf("Hola %c que %s number %u\n", 'v', "tal", 42);
//     //int j = ft_printf("por %% taje\n");
//     //int j = ft_printf("hexa %X\n", 42);
//     //int j = ft_printf("punt %p\n", puntero);
//     //int j = ft_printf("hexa %#x\n", 42);
// 	int j = ft_printf_bonus(" %#x ", -1);
// 	int g = ft_printf_bonus(" %#x ", 1);
//     printf("%d\n", j);
//     printf("%d\n", g);
// 	printf(" %#x ", -1);
//     printf(" %#x ", 1);
//     //printf("num % i\n", 42);
//     //printf("num %+ i\n", 42);
//     //printf("Hola % ffla");
// }
