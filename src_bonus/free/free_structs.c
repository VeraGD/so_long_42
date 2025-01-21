/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:40:36 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/21 12:58:23 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

// auxiliary free counter structure
void	aux_free_counter(t_counter *counter, t_window *window)
{
	if (counter->units_2)
		mlx_delete_image(window->mlx, counter->units_2);
	if (counter->units_3)
		mlx_delete_image(window->mlx, counter->units_3);
	if (counter->units_4)
		mlx_delete_image(window->mlx, counter->units_4);
	if (counter->units_5)
		mlx_delete_image(window->mlx, counter->units_5);
	if (counter->units_6)
		mlx_delete_image(window->mlx, counter->units_6);
	if (counter->units_7)
		mlx_delete_image(window->mlx, counter->units_7);
	if (counter->units_8)
		mlx_delete_image(window->mlx, counter->units_8);
	if (counter->units_9)
		mlx_delete_image(window->mlx, counter->units_9);
	if (window->mlx)
		mlx_terminate(window->mlx);
	if (counter)
		free(counter);
}

// free counter structure
void	free_counter(t_counter *counter, t_window *window)
{
	if (counter->tens_0)
		mlx_delete_image(window->mlx, counter->tens_0);
	if (counter->tens_1)
		mlx_delete_image(window->mlx, counter->tens_1);
	if (counter->tens_2)
		mlx_delete_image(window->mlx, counter->tens_2);
	if (counter->tens_3)
		mlx_delete_image(window->mlx, counter->tens_3);
	if (counter->tens_4)
		mlx_delete_image(window->mlx, counter->tens_4);
	if (counter->tens_5)
		mlx_delete_image(window->mlx, counter->tens_5);
	if (counter->tens_6)
		mlx_delete_image(window->mlx, counter->tens_6);
	if (counter->tens_7)
		mlx_delete_image(window->mlx, counter->tens_7);
	if (counter->tens_8)
		mlx_delete_image(window->mlx, counter->tens_8);
	if (counter->tens_9)
		mlx_delete_image(window->mlx, counter->tens_9);
	if (counter->units_0)
		mlx_delete_image(window->mlx, counter->units_0);
	if (counter->units_1)
		mlx_delete_image(window->mlx, counter->units_1);
	aux_free_counter(counter, window);
}

// auxiliary free window structure
void	aux_free_window(t_window *window)
{
	if (window->exit_u)
		free_doble_image(window->exit_u, window);
	if (window->exit_d)
		free_doble_image(window->exit_d, window);
	if (window->ovni)
		mlx_delete_image(window->mlx, window->ovni);
	if (window->counter)
		free_counter(window->counter, window);
	if (window)
		free(window);
}

// free window structure
void	free_window(t_window *window)
{
	if (window->wall)
		mlx_delete_image(window->mlx, window->wall);
	if (window->collectible)
		mlx_delete_image(window->mlx, window->collectible);
	if (window->player_l)
		free_doble_image(window->player_l, window);
	if (window->player_r)
		free_doble_image(window->player_r, window);
	if (window->player_u)
		free_doble_image(window->player_u, window);
	if (window->player_d)
		free_doble_image(window->player_d, window);
	if (window->floor)
		mlx_delete_image(window->mlx, window->floor);
	if (window->exit_close)
		mlx_delete_image(window->mlx, window->exit_close);
	if (window->exit_open)
		mlx_delete_image(window->mlx, window->exit_open);
	if (window->exit_l)
		free_doble_image(window->exit_l, window);
	if (window->exit_r)
		free_doble_image(window->exit_r, window);
	aux_free_window(window);
}

// free data structure
void	free_data(t_data *data)
{
	if (data)
	{
		if (data->coor_char != NULL)
			free(data->coor_char);
		if (data->coor_exit != NULL)
			free(data->coor_exit);
		if (data->map != NULL)
			free_split(data->map);
		if (data->size != NULL)
			free(data->size);
		if (data->prev != NULL)
			free(data->prev);
		if (data->mov != NULL)
			free(data->mov);
		if (data->collec_ev != NULL)
			free(data->collec_ev);
		if (data->window != NULL)
			free_window(data->window);
		free(data);
		data = NULL;
	}
}
