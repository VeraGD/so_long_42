/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:41:33 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/16 11:54:04 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	aux_rendering(int i, int j, t_window *window, t_data *data)
{
	mlx_t	*mlx;

	mlx = window->mlx;
	if (data->map[i][j] == 'C')
	{
		if (mlx_image_to_window(mlx, window->collectible, j * 100, i * 100) < 0)
			error();
	}
	else if (data->map[i][j] == '0')
	{
		if (mlx_image_to_window(mlx, window->floor, j * 100, i * 100) < 0)
			error();
	}
	else if (data->map[i][j] == 'P')
	{
		if (mlx_image_to_window(mlx, window->player_d, j * 100, i * 100) < 0)
			error();
	}
}

// function to render the walls
static void	rendering_wall(t_window *window, int j, int i)
{
	if (mlx_image_to_window(window->mlx, window->wall, j * 100, i * 100) < 0)
		error();
}

// function to render the exit
static void	rendering_exit(t_window *window, int j, int i)
{
	mlx_t	*mlx;

	mlx = window->mlx;
	if (mlx_image_to_window(mlx, window->exit_close, j * 100, i * 100) < 0)
		error();
}

void	rendering(t_data *data, t_window *window)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				rendering_wall(window, j, i);
			else if (data->map[i][j] == 'E')
				rendering_exit(window, j, i);
			aux_rendering(i, j, window, data);
			j++;
		}
		i++;
	}
}
