/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:37:45 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/12 08:42:09 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	int	flag;

	flag = (ft_isalpha(c) || ft_isdigit(c));
	return (flag);
}

/*int	main(void)
{
	int	a = ' ';
	int	c = ft_isalnum(a);
	int	e = isalnum(a);
	printf("Mi funct %d\n", c);
	printf("La otra funct %d\n", e);
}*/
