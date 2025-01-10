/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:41:30 by veragarc          #+#    #+#             */
/*   Updated: 2024/12/13 16:43:42 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// Calculates length of how many char * there are in a char **.
size_t	ft_len_double(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

// Creates a deep copy of char **, a copy that can be 
// modified without modifying the original one.
char	**deep_copy(char **original)
{
	size_t	i;
	size_t	j;
	char	**copy;

	i = ft_len_double(original);
	copy = (char **)malloc((i + 1) * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		copy[j] = ft_strdup(original[j]);
		if (copy[j] == NULL)
		{
			free_map_number(copy, j);
			return (NULL);
		}
		j++;
	}
	copy[i] = NULL;
	return (copy);
}

void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
