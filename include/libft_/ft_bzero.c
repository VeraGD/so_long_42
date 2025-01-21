/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:44:47 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/12 10:44:49 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int	main(void)
{
	char *str = "abcdef";
	size_t i = 3;
	ft_bzero(str, i);
	//printf(" %s\n", str);
	printf("%c", str[0]);
	printf("%c", str[1]);
	printf("%c", str[2]);
	printf("%c", str[3]);
	printf("%c", str[4]);
	printf("%c\n", str[5]);
}*/
