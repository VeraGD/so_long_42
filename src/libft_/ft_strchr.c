/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:59:57 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/12 09:00:01 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)s;
	while (res[i] != '\0')
	{
		if (res[i] == (char)c)
			return (&res[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&res[i]);
	else
		return (NULL);
}

/*int	main(void)
{
	char arr[] = "abcdc";
	//char *arr = NULL;
	int c = 'c';
	const char *res = ft_strchr(arr, c);
	printf("%s\n", res);
	char *w = strchr(arr, c);
	printf("%s\n", w);
}*/
