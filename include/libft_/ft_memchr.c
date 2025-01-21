/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:59:26 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/22 11:32:41 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char *)s;
	while (i < n)
	{
		if (res[i] == (unsigned char)c)
			return ((void *)&res[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char arr[] = "abcdc";
	//char *arr = NULL;
	int c = 'b';
	char *s = ft_memchr(arr, c, 3);
	printf(" %s\n", s);
	char ar[] = "abcdc";
	//char *ar = NULL;
	char *g = memchr(ar, c, 3); // Original con NULL peta
	printf(" %s\n", g);
}*/
