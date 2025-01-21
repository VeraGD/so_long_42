/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:53:41 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/09 12:10:10 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isprint(int c)
{
	int	flag;

	flag = 0;
	if (c >= 32 && c <= 126)
		flag = 1;
	return (flag);
}

/*int     main(void)
{
        int     a = 78;
        int     c = ft_isprint(a);
        int     e = isprint(a);
        printf("Mi funct %d\n", c);
        printf("La otra funct %d\n", e);
}*/
