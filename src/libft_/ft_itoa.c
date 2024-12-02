/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:56:48 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/21 13:07:38 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

static char	*memory(long n)
{
	long	i;
	char	*r;
	int		cont;

	i = 1;
	cont = 1;
	if (n < 0)
	{
		n = n * -1;
		cont++;
	}
	while (n / i >= 10)
	{
		i = i * 10;
		cont++;
	}
	r = (char *)malloc(cont + 1);
	return (r);
}

static char	*aux_itoa(long n, char *r)
{
	int		index;
	long	i;

	i = 1;
	index = 0;
	n = (long)n;
	if (n < 0)
	{
		r[index] = '-';
		n = n * -1;
		index++;
	}
	while (n / i >= 10)
		i = i * 10;
	while (i > 0)
	{
		r[index] = n / i + '0';
		n = n % i;
		i = i / 10;
		index++;
	}
	r[index] = '\0';
	return (r);
}

char	*ft_itoa(int n)
{
	char	*r;
	long	num;

	num = (long)n;
	r = memory(num);
	if (r == NULL)
		return (NULL);
	r = aux_itoa(num, r);
	return (r);
}

/*int	main(void)
{
	int j = -2147483648;
	char  *s = ft_itoa(j);
	printf("%s\n", s);
}*/
