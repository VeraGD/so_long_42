/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:43:14 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/12 11:20:31 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && (i + j) < len && big[i + j] != '\0')
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}

/*int	main(void)
{
	const char str[] = "Hello, this is a simple test.";
	const char to_find[] = "simple";
	//const char *str = NULL;
	//const char *to_find = NULL;
	size_t i = 23;
	char *res = ft_strnstr(str, to_find, i);
	printf("%s\n", res);
	if (res != NULL)
		printf("%s\n", res);
	else
		printf("Substring not found within the first %zu characters.\n", i);
}*/
