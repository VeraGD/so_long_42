/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:13:24 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/09 11:27:58 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isalpha(int c)
{
	int	flag;

	flag = 0;
	if (c >= 'a' && c <= 'z')
		flag = 1;
	else if (c >= 'A' && c <= 'Z')
		flag = 1;
	return (flag);
}

/*int	main(void)
{
	int	a = 'a';
	int	c = ft_isalpha(a);
	int	e = isalpha(a);
	printf("Mi funct %d\n", c);
	printf("La otra funct %d\n", e);
}*/
