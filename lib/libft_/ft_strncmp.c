/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:52:08 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/12 11:17:14 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*r1;
	char	*r2;

	i = 0;
	r1 = (char *)s1;
	r2 = (char *)s2;
	while (r1[i] == r2[i] && (r1[i] != '\0' && r2[i] != '\0') && i < n - 1)
		i++;
	if (n == 0)
		return (0);
	else
		return ((unsigned char)r1[i] - (unsigned char)r2[i]);
}

/*int	main(void)
{
	const char s1[] = "abad";
	const char s2[] = "abad";
	//const char *s1 = NULL;
	//const char *s2 = NULL;
	size_t i = 10;
	int j = ft_strncmp(s1, s2, i);
	int k = strncmp(s1, s2, i);
	printf("Mi funct %d\n", j);
	printf("La otra funct %d\n", k);
}*/
