/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:31:05 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/12 10:31:10 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)s;
	while (i < n)
	{
		res[i] = (char)c;
		i++;
	}
	return (res);
}

/*int	main(void)
{
	char str[] = "abcdef";
	//char s[] = "abcdef";
	//char *n = NULL;
	ft_memset(str, 'Z', 7);
	//memset(s, 'Z', 7);
	printf(" %s\n", str);
	//printf(" %s\n", s);
}*/
