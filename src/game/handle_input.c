/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:21:01 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/16 11:38:04 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// Pressing the ESC key closes the game
static void	check_exit(mlx_key_data_t key_data, t_window *window)
{
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
	{
		mlx_close_window(window->mlx);
		window->mlx = NULL;
		ft_printf("You closed the game\n");
		exit(0);
	}
}

// aux handle input, check more keys
void	aux_handle_input(mlx_key_data_t key_data, t_data *data)
{
	t_window	*window;

	window = data->window;
	if ((key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT)
		&& key_data.action == MLX_PRESS)
	{
		data->direction = 'l';
		check_direction(data, window);
	}
	else if ((key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT)
		&& key_data.action == MLX_PRESS)
	{
		data->direction = 'r';
		check_direction(data, window);
	}
}

// The keys are related to an address and the check_direction function is called
void	handle_input(mlx_key_data_t key_data, void *param)
{
	t_window	*window;
	t_data		*data;

	data = (t_data *)param;
	window = data->window;
	check_exit(key_data, window);
	if ((key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP)
		&& key_data.action == MLX_PRESS)
	{
		data->direction = 'u';
		check_direction(data, window);
	}
	else if ((key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN)
		&& key_data.action == MLX_PRESS)
	{
		data->direction = 'd';
		check_direction(data, window);
	}
	else
		aux_handle_input(key_data, data);
}
