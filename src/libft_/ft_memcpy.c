/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:11:44 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/16 15:43:49 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char str[] = "abcde";
	//char *str = NULL;
	char dest[4] = "fgh";
	//char *dest = NULL;
	printf(" %s\n", dest);
	size_t i = 5;
	ft_memcpy(dest, str, i);
	printf(" %s\n", dest);
	char d[] = "fgh";
	//char *d = NULL;
	printf(" %s\n", d);
	memcpy(d, str, i); // con NULL peta
	printf(" %s\n", d);
}*/
