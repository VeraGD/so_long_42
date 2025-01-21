/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:32:16 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/16 10:37:57 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

// draws the floor each time the character passes
void	draw_floor(t_window *window, t_data *data)
{
	int	col;
	int	row;
	int	*prev;

	col = data->prev[1] * 100;
	row = data->prev[0] * 100;
	prev = data->prev;
	if (data->upper_exit == 'y' && data->map[prev[0]][prev[1]] == 'E')
		mlx_image_to_window(window->mlx, window->exit_close, col, row);
	else if (data->upper_exit == 'y' && data->map[prev[0]][prev[1]] == '0')
		mlx_image_to_window(window->mlx, window->floor, col, row);
	else
		mlx_image_to_window(window->mlx, window->floor, col, row);
}

// draws the character as it passes over the closed exit
static void	draw_player_over(t_window *window, t_data *data, int row, int col)
{
	if (data->direction == 'r')
		mlx_image_to_window(window->mlx, window->exit_r[data->ev], col, row);
	else if (data->direction == 'l')
		mlx_image_to_window(window->mlx, window->exit_l[data->ev], col, row);
	else if (data->direction == 'u')
		mlx_image_to_window(window->mlx, window->exit_u[data->ev], col, row);
	else if (data->direction == 'd')
		mlx_image_to_window(window->mlx, window->exit_d[data->ev], col, row);
}

// draws the character when it moves
void	draw_player(t_window *window, t_data *data)
{
	int	col;
	int	row;

	col = data->mov[1] * 100;
	row = data->mov[0] * 100;
	if (data->upper_exit == 'y' && data->map[data->mov[0]][data->mov[1]] == 'E')
		draw_player_over(window, data, row, col);
	else if (data->direction == 'r')
		mlx_image_to_window(window->mlx, window->player_r[data->ev], col, row);
	else if (data->direction == 'd')
		mlx_image_to_window(window->mlx, window->player_d[data->ev], col, row);
	else if (data->direction == 'u')
		mlx_image_to_window(window->mlx, window->player_u[data->ev], col, row);
	else if (data->direction == 'l')
		mlx_image_to_window(window->mlx, window->player_l[data->ev], col, row);
}
