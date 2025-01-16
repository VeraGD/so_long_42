/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   made_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:01:20 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/16 12:57:14 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// game closes if you win
static void	exit_game(t_window *window, t_data *data)
{
	mlx_close_window(window->mlx);
	window->mlx = NULL;
	ft_printf("Moves: %d\n", data->cont + 1);
	ft_printf("YOU WIN!\n");
	free(data);
	exit(0);
}

// auxiliary that opens the door
static void	aux_made_move(t_data *data, t_window *window)
{
	int		row;
	int		col;
	mlx_t	*mlx;

	row = data->coor_exit[1];
	col = data->coor_exit[0];
	mlx = window->mlx;
	if (mlx_image_to_window(mlx, window->exit_open, row * 100, col * 100) < 0)
		error();
	data->exit_status = 'o';
}

// generates the movement taking into account the output 
// and the collectibles
void	made_move(t_data *data, t_window *window)
{
	if (data->map[data->mov[0]][data->mov[1]] == 'C')
	{
		data->collectionables--;
		if (data->collectionables == 0)
			aux_made_move(data, window);
		draw_floor(window, data);
		draw_player(window, data);
	}
	if (data->map[data->mov[0]][data->mov[1]] == 'E')
	{
		if (data->exit_status == 'c')
			data->upper_exit = 'y';
		else
			exit_game(window, data);
		draw_floor(window, data);
		draw_player(window, data);
	}
	else
	{
		draw_floor(window, data);
		draw_player(window, data);
		data->upper_exit = 'n';
	}
	data->cont++;
	ft_printf("Moves: %d\n", data->cont);
}
