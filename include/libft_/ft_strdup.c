/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:21:05 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/16 15:55:21 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	j;
	char	*copy;

	i = ft_strlen(src);
	copy = (char *)malloc(i + 1);
	if (copy == NULL)
		return (NULL);
	j = 0;
	while (src[j] != '\0')
	{
		copy[j] = src[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

/*int	main(void)
{
	const char *s = "abc";
	char *c = ft_strdup(s);
	//char *g = strdup(s);
	printf(" %s\n", c);
	//printf("%s\n", g);
}*/
