/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:15:16 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/12 13:20:40 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	i;

	if (s != NULL)
	{
		len = ft_strlen(s);
		i = 0;
		while (i < len)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

/*int	main(void)
{
	char	str[] = "abcde";
	//char	*s = NULL;
	ft_putstr_fd(str, 1);
}*/
