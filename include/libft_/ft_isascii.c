/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:43:45 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/09 11:48:58 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isascii(int c)
{
	int	flag;

	flag = 0;
	if (c >= 0 && c <= 127)
		flag = 1;
	return (flag);
}

/*int	main(void)
{
	int	a = '~';
	int	c = ft_isascii(a);
	int	e = isascii(a);
	printf("Mi funct %d\n", c);
	printf("La otra funct %d\n", e);
}*/
