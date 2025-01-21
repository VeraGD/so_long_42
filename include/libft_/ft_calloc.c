/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:52:43 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/12 10:53:59 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*s;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	total = nmemb * size;
	s = malloc(total);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, total);
	return (s);
}

/*int	main(void)
{
	size_t i = 0;
	size_t j = 0;
	char *res = ft_calloc(i, j);
	//char *res = calloc(i, j);
	//printf("%d\n", (int)strlen(res));
	printf(" %s\n", (res));
	printf(" %c\n", (res[0]));
	printf(" %c\n", (res[1]));
}*/
