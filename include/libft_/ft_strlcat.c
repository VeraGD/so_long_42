/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:15:46 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/12 10:15:57 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len_src);
	if (size <= len_dest)
		return (len_src += size);
	else
		len_src += len_dest;
	while (src[i] != '\0' && len_dest < size - 1)
	{
		dest[len_dest] = src[i];
		i++;
		len_dest++;
	}
	dest[len_dest] = '\0';
	return (len_src);
}

/*int	main(void)
{
	char dest[] = "de";
	char src[] = "abc";
	//char *dest = NULL;
	//char *src = NULL;

	unsigned int s = ft_strlcat(dest, src, -1);
	printf("%d\n", s);
	printf("%s\n", dest);
}*/
