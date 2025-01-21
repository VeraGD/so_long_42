/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:28:18 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/09 11:35:33 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	int	flag;

	flag = 0;
	if (c >= '0' && c <= '9')
		flag = 1;
	return (flag);
}

/*int	main(void)
{
	int	a = '7';
	int	c = ft_isdigit(a);
	int	e = isdigit(a);
	printf("Mi funct %d\n", c);
	printf("La otra funct %d\n", e);
}*/
