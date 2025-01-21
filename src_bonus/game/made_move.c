/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   made_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:01:20 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/21 12:50:30 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

// calculates the number of the evolution [0, 1, 2, 3]
void	number_evolution(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (data->count_col == data->collec_ev[i])
			data->ev = i + 1;
		i++;
	}
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

// auxiliary that process when the player get a C
void	aux_c_made_move(t_data *data, t_window *window)
{
	data->count_col++;
	number_evolution(data);
	data->collectionables--;
	data->map[data->mov[0]][data->mov[1]] = '0';
	if (data->collectionables == 0)
		aux_made_move(data, window);
	draw_floor(window, data);
	draw_player(window, data);
}

// generates the movement taking into account the output 
// and the collectibles
void	made_move(t_data *data, t_window *window)
{
	if (data->map[data->mov[0]][data->mov[1]] == 'C')
		aux_c_made_move(data, window);
	else if (data->map[data->mov[0]][data->mov[1]] == 'E')
	{
		if (data->exit_status == 'c')
			data->upper_exit = 'y';
		else
			exit_game(window, data);
		draw_floor(window, data);
		draw_player(window, data);
	}
	else if (data->map[data->mov[0]][data->mov[1]] == 'G')
	{
		exit_game_over(window, data);
	}
	else
	{
		draw_floor(window, data);
		draw_player(window, data);
		data->upper_exit = 'n';
	}
	data->cont++;
	render_counter(data, window, window->counter);
}
