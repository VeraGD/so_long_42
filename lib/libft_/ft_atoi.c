/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:41:12 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/21 13:08:19 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	long	num;
	int		r;

	i = 0;
	num = 0;
	r = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			r = -1;
		else
			r = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	if (r * num < -2147483648 || r * num > 2147483647)
		return (0);
	return (r * num);
}

/*int	main(void)
{
	char	*d = NULL;
	char	e[] = " -00206ty6 -";
	char	f[] = " -2000ty6 -";
	char	g[] = " -f20202ty6 -";
	//int		j;
	int		k;
	int		l;
	int		m;

	int j = ft_atoi(d);
	//int n = atoi(d);
	printf("m %d\n", j);
	//printf("f %d\n", n);
	k = ft_atoi(e);
	int o = atoi(e);
	printf("m %d\n", k);
	printf("f %d\n", o);
	l = ft_atoi(f);
	int p = atoi(f);
	printf("m %d\n", l);
	printf("f %d\n", p);
	m = ft_atoi(g);
	int q = atoi(g);
	printf("m %d\n", m);
	printf("f %d\n", q);
}*/
