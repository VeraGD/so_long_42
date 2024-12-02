/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:45:47 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/14 10:13:33 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	c;

	i = 1;
	if (n > -2147483648 && n < 2147483647)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * -1;
		}
		while (n / i >= 10)
			i = i * 10;
		while (i > 0)
		{
			c = n / i + '0';
			write(fd, &c, 1);
			n = n % i;
			i = i / 10;
		}
	}
	else if (n == 2147483647)
		write(fd, "2147483647", 10);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
}

/*int	main(void)
{
	int	i;
	int	fd = 1;

	i = -2147483648;
	ft_putnbr_fd(i, fd);
}*/
