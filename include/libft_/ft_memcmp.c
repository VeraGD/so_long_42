/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:19:23 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/16 15:39:43 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ss1;
	char	*ss2;
	size_t	i;

	i = 0;
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	while (i < n)
	{
		if ((unsigned char)ss1[i] != (unsigned char)ss2[i])
		{
			return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
		}
		i++;
	}
	return (0);
}

/*int	main()
{
	char s1[] = "abcd";
	char s2[] = "abad";
	//char *s1 = NULL;
	//char *s2 = NULL;
	int j = ft_memcmp(s1, s2, 3);
	printf(" %d\n", j);
	int k = memcmp(s1, s2, 3);
	printf(" %d\n", k);
}*/
