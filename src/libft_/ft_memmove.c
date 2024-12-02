/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:11:24 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/12 12:30:06 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

static void	*aux_if(size_t n, const char *s, char *d)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		i--;
		d[i] = s[i];
	}
	return (d);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dest;
	s = (const char *)src;
	if (d > s && d < s + n)
	{
		aux_if(n, s, d);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}

/*int	main(void)
{
	//char str[] = "abcde";
	char *str = NULL;
	char dest[] = "def";
	//char *dest = NULL;
	printf(" %s\n", dest);
	size_t i = 10;
	ft_memmove(dest, str, i);
	printf(" %s\n", dest);
}*/
