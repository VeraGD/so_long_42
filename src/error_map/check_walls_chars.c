/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:54:02 by veragarc          #+#    #+#             */
/*   Updated: 2024/12/13 16:02:44 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// Check that the map consists only of valid characters (1, 0, E, P, C).
int	check_chars(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P')
		{
			if (map[i] != 'E' && map[i] != 'C' && map[i] != '\n')
				return (1);
		}
		i++;
	}
	return (0);
}

// Check that the map contains the indicated number of characters 
// (a single exit E, a single character P, at least one collectible C).
int	check_number_chars(char *map)
{
	int	i;
	int	conte;
	int	contp;
	int	contc;

	i = 0;
	conte = 0;
	contp = 0;
	contc = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			conte += 1;
		else if (map[i] == 'P')
			contp += 1;
		else if (map[i] == 'C')
			contc += 1;
		i++;
	}
	if (conte != 1 || contp != 1 || contc == 0)
		return (1);
	return (0);
}

// Auxiliary function to check_walls, checks that the first 
// and last columns are walls (1).
static int	aux_check_walls(char *map)
{
	int		i;
	char	**split;

	i = 1;
	split = ft_split(map, '\n');
	while (i < (int)ft_len_double(split) - 1)
	{
		if (split[i][0] != '1' || split[i][ft_strlen(split[i]) - 1] != '1')
		{
			free_split(split);
			return (1);
		}
		i++;
	}
	free_split(split);
	return (0);
}

// Auxiliary function to check_walls, it frees memory, 
// and returns 1, error.
static int	aux_aux_check_walls(char **split)
{
	free_split(split);
	return (1);
}

// Check that there are walls around the map 
// (first row, last row, first column, last column)
int	check_walls(char *map)
{
	char	**split;
	int		i;
	int		j;
	int		row_length;

	split = ft_split(map, '\n');
	i = 0;
	while (i < (int)ft_len_double(split) - 1)
	{
		row_length = ft_strlen(split[i]);
		if (i == 0 || i == (int)ft_len_double(split) - 1)
		{
			j = 0;
			while (j < row_length)
			{
				if (split[i][j] != '1')
					return (aux_aux_check_walls(split));
				j++;
			}
		}
		i++;
	}
	free_split(split);
	return (aux_check_walls(map));
}
