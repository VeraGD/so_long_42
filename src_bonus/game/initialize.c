/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:10:22 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/21 12:52:40 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

// initializes the counter structure (mlx and textures used)
static t_counter	*initiaize_counter(mlx_t *mlx)
{
	t_counter	*counter;

	counter = (t_counter *)malloc(sizeof(t_counter));
	counter->tens_0 = load_texture(mlx, "imgs/tens_0.png");
	counter->tens_1 = load_texture(mlx, "imgs/tens_1.png");
	counter->tens_2 = load_texture(mlx, "imgs/tens_2.png");
	counter->tens_3 = load_texture(mlx, "imgs/tens_3.png");
	counter->tens_4 = load_texture(mlx, "imgs/tens_4.png");
	counter->tens_5 = load_texture(mlx, "imgs/tens_5.png");
	counter->tens_6 = load_texture(mlx, "imgs/tens_6.png");
	counter->tens_7 = load_texture(mlx, "imgs/tens_7.png");
	counter->tens_8 = load_texture(mlx, "imgs/tens_8.png");
	counter->tens_9 = load_texture(mlx, "imgs/tens_9.png");
	counter->units_0 = load_texture(mlx, "imgs/units_0.png");
	counter->units_1 = load_texture(mlx, "imgs/units_1.png");
	counter->units_2 = load_texture(mlx, "imgs/units_2.png");
	counter->units_3 = load_texture(mlx, "imgs/units_3.png");
	counter->units_4 = load_texture(mlx, "imgs/units_4.png");
	counter->units_5 = load_texture(mlx, "imgs/units_5.png");
	counter->units_6 = load_texture(mlx, "imgs/units_6.png");
	counter->units_7 = load_texture(mlx, "imgs/units_7.png");
	counter->units_8 = load_texture(mlx, "imgs/units_8.png");
	counter->units_9 = load_texture(mlx, "imgs/units_9.png");
	return (counter);
}

// Load all the evolution of a direction sprint
mlx_image_t	**load_sprints(char *path, mlx_t *mlx)
{
	char		**split;
	char		*join;
	mlx_image_t	**res;

	split = ft_split(path, '.');
	res = (mlx_image_t **)malloc(4 * sizeof(mlx_image_t *));
	if (!res)
		error();
	res[0] = load_texture(mlx, path);
	join = ft_strjoin(split[0], "_1.png");
	res[1] = load_texture(mlx, join);
	free(join);
	join = ft_strjoin(split[0], "_2.png");
	res[2] = load_texture(mlx, join);
	free(join);
	join = ft_strjoin(split[0], "_3.png");
	res[3] = load_texture(mlx, join);
	free(join);
	free_split(split);
	return (res);
}

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
	window->player_l = load_sprints("imgs/cow_l.png", mlx);
	window->player_r = load_sprints("imgs/cow_r.png", mlx);
	window->player_u = load_sprints("imgs/cow_u.png", mlx);
	window->player_d = load_sprints("imgs/cow_d.png", mlx);
	window->floor = load_texture(mlx, "imgs/background.png");
	window->exit_close = load_texture(mlx, "imgs/exit_c.png");
	window->exit_open = load_texture(mlx, "imgs/exit_o.png");
	window->exit_l = load_sprints("imgs/over_l.png", mlx);
	window->exit_r = load_sprints("imgs/over_r.png", mlx);
	window->exit_u = load_sprints("imgs/over_u.png", mlx);
	window->exit_d = load_sprints("imgs/over_d.png", mlx);
	window->ovni = load_texture(mlx, "imgs/ovni.png");
	window->counter = initiaize_counter(mlx);
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
	data->ev = 0;
	data->collec_ev = get_collect_eval(data->map);
	data->count_col = 0;
	free_split(map_double);
	return (data);
}
