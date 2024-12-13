/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:40:36 by veragarc          #+#    #+#             */
/*   Updated: 2024/12/13 16:41:11 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// Free memory of double pointer
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Free memory from double pointer indicating
// the index at which to start freeing memory (from back to front).
void	free_map_number(char **copy, size_t j)
{
	size_t	k;

	k = 0;
	while (k < j)
	{
		free(copy[k]);
		k++;
	}
	free(copy);
}
