/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:40:36 by veragarc          #+#    #+#             */
/*   Updated: 2024/12/13 16:41:11 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// Free memory of double pointer
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Free memory from double pointer indicating
// the index at which to start freeing memory (from back to front).
void	free_map_number(char **copy, size_t j)
{
	size_t	k;

	k = 0;
	while (k < j)
	{
		free(copy[k]);
		k++;
	}
	free(copy);
}

/* void	free_window(t_window *window)
{
	if (window)
	{
		if (window->mlx != NULL)
			free(window->mlx);
		if (window->wall != NULL)
			free(window->wall);
		if (window->floor != NULL)
			free(window->floor);
		if (window->player != NULL)
			free(window->player);
		if (window->collectible != NULL)
			free(window->collectible);
		if (window->exit_close != NULL)
			free(window->exit_close);
		if (window->exit_open != NULL)
			free(window->exit_open);
		free(window);
		window = NULL;
	}
} */
/* void	free_window(t_window *window)
{
	if (window->wall)
        mlx_delete_image(window->mlx, window->wall);
    if (window->collectible)
        mlx_delete_image(window->mlx, window->collectible);
    if (window->player_l)
        mlx_delete_image(window->mlx, window->player_l);
	if (window->player_r)
    	mlx_delete_image(window->mlx, window->player_r);
	if (window->player_u)
        mlx_delete_image(window->mlx, window->player_u);
	if (window->player_d)
        mlx_delete_image(window->mlx, window->player_d);
    if (window->floor)
        mlx_delete_image(window->mlx, window->floor);
    if (window->exit_close)
        mlx_delete_image(window->mlx, window->exit_close);
    if (window->exit_open)
        mlx_delete_image(window->mlx, window->exit_open);
	if (window->exit_open_open)
    	mlx_delete_image(window->mlx, window->exit_open_open);
	if (window->exit_player)
        mlx_delete_image(window->mlx, window->exit_player);
    if (window->mlx)
		mlx_terminate(window->mlx);
    if (window)
    	free(window);
} */

void free_window(t_window *window)
{
	if (window->wall)
        mlx_delete_image(window->mlx, window->wall);
	if (window->collectible)
        mlx_delete_image(window->mlx, window->collectible);
	if (window->player_l)
        mlx_delete_image(window->mlx, window->player_l);
	if (window->player_r)
        mlx_delete_image(window->mlx, window->player_r);
	if (window->player_u)
        mlx_delete_image(window->mlx, window->player_u);
	if (window->player_d)
        mlx_delete_image(window->mlx, window->player_d);
	if (window->floor)
        mlx_delete_image(window->mlx, window->floor);
	if (window->exit_close)
        mlx_delete_image(window->mlx, window->exit_close);
	if (window->exit_open)
        mlx_delete_image(window->mlx, window->exit_open);
	if (window->exit_l)
        mlx_delete_image(window->mlx, window->exit_l);
	if (window->exit_r)
		mlx_delete_image(window->mlx, window->exit_r);
	if (window->exit_u)
		mlx_delete_image(window->mlx, window->exit_u);
	if (window->exit_d)
		mlx_delete_image(window->mlx, window->exit_d);
    if (window->mlx)
        mlx_terminate(window->mlx);
    if (window)
        free(window);
}

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
		if (data->map_print != NULL)
			free_split(data->map_print);
		if (data->size != NULL)
			free(data->size);
		if (data->prev != NULL)
			free(data->prev);
		if (data->mov != NULL)
			free(data->mov);
		if (data->window != NULL)
			free_window(data->window);
		free(data);
		data = NULL;
	}
}
