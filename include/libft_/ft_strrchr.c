/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:03:55 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/12 09:03:58 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;
	char	*conv;

	i = 0;
	conv = (char *)s;
	res = NULL;
	while (conv[i] != '\0')
	{
		if (conv[i] == (char)c)
			res = &conv[i];
		i++;
	}
	if ((char)c == '\0')
		return (&conv[i]);
	return (res);
}

/*int	main(void)
{
	//char arr[] = "abcdcfcdg";
	char *arr = NULL;
	int c = 'c';
	const char *res = ft_strrchr(arr, c);
	printf(" %s\n", res);
	const char *w = strrchr(arr, c); // si metes NULL peta
	printf(" %s\n", w);
}*/
