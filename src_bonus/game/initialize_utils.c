/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:15:10 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/21 12:55:41 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

// returns as int * the coordinates in which the character is located
// (rows, columns)
void	*find_char(char **map, char to_find)
{
	int	i;
	int	j;
	int	*coor;

	i = 0;
	coor = (int *)malloc(2 * sizeof(int));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == to_find)
			{
				coor[0] = i;
				coor[1] = j;
				return (coor);
			}
			j++;
		}
		i++;
	}
	free(coor);
	return (NULL);
}

// returns as int * the size of the map (rows, columns)
int	*get_size_map(char **map)
{
	int	*size;

	size = (int *)malloc(2 * sizeof(int));
	size[0] = (int)ft_len_double(map);
	size[1] = (int)ft_strlen(map[0]);
	return (size);
}

// load the images and then the textures (the ones that are finally used)
mlx_image_t	*load_texture(mlx_t *mlx, char *file)
{
	mlx_texture_t	*texture;
	mlx_image_t		*imagen;

	texture = mlx_load_png(file);
	if (!texture)
		error();
	imagen = mlx_texture_to_image(mlx, texture);
	if (!imagen)
	{
		mlx_delete_texture(texture);
		error();
	}
	mlx_delete_texture(texture);
	return (imagen);
}

// returns an *int of size 2 with two zeros as parameters
int	*generate_zeros(void)
{
	int	*res;

	res = (int *)malloc(2 * sizeof(int));
	res[0] = 0;
	res[1] = 0;
	return (res);
}

// gets the numbers of collects in which the cow evolut
int	*get_collect_eval(char **map)
{
	int	c;
	int	*res;
	int	scale;
	int	rest;

	c = find_collectionables(map);
	res = (int *)malloc(3 * (sizeof(int)));
	if (!res)
		error();
	scale = c / 3;
	rest = c % 3;
	if (rest == 1 || rest == 0)
	{
		res[0] = scale + rest;
		res[1] = 2 * scale + rest;
		res[2] = 3 * scale + rest;
	}
	else if (rest == 2)
	{
		res[0] = scale + 1;
		res[1] = 2 * scale + 2;
		res[2] = 3 * scale + 2;
	}
	return (res);
}
