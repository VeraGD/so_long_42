/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:03:00 by veragarc          #+#    #+#             */
/*   Updated: 2024/12/13 16:22:32 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// Gets the position of the character, returns an int *, (row, column).
static int	*find_character(char **map)
{
	int	i;
	int	j;
	int	*coordinates;

	i = 0;
	coordinates = (int *)malloc(2 * sizeof(int));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				coordinates[0] = i;
				coordinates[1] = j;
				return (coordinates);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

// Counts how many collectibles C are on a map.
static int	find_collectionables(char **map)
{
	int	i;
	int	j;
	int	cont;

	i = 0;
	cont = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				cont += 1;
			}
			j++;
		}
		i++;
	}
	return (cont);
}

// By recursivity is doing a fill_gaps, from the position of the character it 
// fills the map with 2s and it is counting the number of collectibles through 
// which it passes, and whether or not it passes through the exit.
static void	fill_gaps(int filas, int columnas, char **map, int *cont)
{
	if (map[filas][columnas] == '0' || map[filas][columnas] == 'C')
	{
		if (map[filas][columnas] == 'C')
			cont[0] += 1;
		map[filas][columnas] = '2';
		fill_gaps(filas, columnas + 1, map, cont);
		fill_gaps(filas, columnas - 1, map, cont);
		fill_gaps(filas + 1, columnas, map, cont);
		fill_gaps(filas - 1, columnas, map, cont);
	}
	if (map[filas][columnas] == 'E' || map[filas][columnas] == 'P')
	{
		if (map[filas][columnas] == 'E')
			cont[1] += 1;
		map[filas][columnas] = '2';
		fill_gaps(filas, columnas + 1, map, cont);
		fill_gaps(filas, columnas - 1, map, cont);
		fill_gaps(filas + 1, columnas, map, cont);
		fill_gaps(filas - 1, columnas, map, cont);
	}
}

// Check that the exit can be reached and that all collectibles can be 
// collected.
int	check_way(char *map)
{
	int		*cont;
	int		*coords;
	char	**map2;
	char	**m;

	m = ft_split(map, '\n');
	map2 = deep_copy(m);
	coords = find_character(map2);
	if (coords == NULL)
		return (1);
	cont = (int *)malloc(2 * sizeof(int));
	cont[0] = 0;
	cont[1] = 0;
	fill_gaps(coords[0], coords[1], map2, cont);
	free(coords);
	free_split(map2);
	if (cont[1] == 1 && cont[0] == (int)find_collectionables(m))
	{
		free_split(m);
		return (0);
	}
	free_split(m);
	return (1);
}
