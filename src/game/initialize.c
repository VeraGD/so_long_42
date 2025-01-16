/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:10:22 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/16 10:14:28 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// initializes the MLX structure (mlx and textures used)
static t_window	*initiaize_window(int *size)
{
	t_window	*window;
	mlx_t		*mlx;

	window = (t_window *)malloc(sizeof(t_window));
	mlx = mlx_init(size[1] * 100, size[0] * 100, "So long", true);
	if (!mlx)
		error();
	window->mlx = mlx;
	window->wall = load_texture(mlx, "imgs/bush.png");
	window->collectible = load_texture(mlx, "imgs/dna.png");
	window->player_l = load_texture(mlx, "imgs/cow_l.png");
	window->player_r = load_texture(mlx, "imgs/cow_r.png");
	window->player_u = load_texture(mlx, "imgs/cow_u.png");
	window->player_d = load_texture(mlx, "imgs/cow_d.png");
	window->floor = load_texture(mlx, "imgs/background.png");
	window->exit_close = load_texture(mlx, "imgs/exit_c.png");
	window->exit_open = load_texture(mlx, "imgs/exit_o.png");
	window->exit_l = load_texture(mlx, "imgs/over_l.png");
	window->exit_r = load_texture(mlx, "imgs/over_r.png");
	window->exit_u = load_texture(mlx, "imgs/over_u.png");
	window->exit_d = load_texture(mlx, "imgs/over_d.png");
	return (window);
}

// initializes the basic data structure of the map
t_data	*initiaize_data(char *map)
{
	char	**map_double;
	char	**map_copy;
	t_data	*data;

	map_double = ft_split(map, '\n');
	map_copy = deep_copy(map_double);
	data = (t_data *)malloc(sizeof(t_data));
	data->map = map_copy;
	data->collectionables = find_collectionables(map_copy);
	data->coor_char = find_char(map_copy, 'P');
	data->size = get_size_map(map_copy);
	data->window = initiaize_window(data->size);
	data->coor_exit = find_char(map_copy, 'E');
	data->direction = 'i';
	data->exit_status = 'c';
	data->upper_exit = 'n';
	data->mov = generate_zeros();
	data->prev = generate_zeros();
	data->cont = 0;
	free_split(map_double);
	return (data);
}
