/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:48:23 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/16 10:53:40 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// get and change the coordinates to move upwards
static void	move_up(t_data *data, t_window *window)
{
	data->mov[0] = data->coor_char[0] - 1;
	data->mov[1] = data->coor_char[1];
	if (data->map[data->mov[0]][data->mov[1]] != '1')
	{
		data->coor_char[0]--;
		made_move(data, window);
	}
}

// get and change the coordinates to move downwards
static void	move_down(t_data *data, t_window *window)
{
	data->mov[0] = data->coor_char[0] + 1;
	data->mov[1] = data->coor_char[1];
	if (data->map[data->mov[0]][data->mov[1]] != '1')
	{
		data->coor_char[0]++;
		made_move(data, window);
	}
}

// get and change the coordinates to move to the left
static void	move_left(t_data *data, t_window *window)
{
	data->mov[0] = data->coor_char[0];
	data->mov[1] = data->coor_char[1] - 1;
	if (data->map[data->mov[0]][data->mov[1]] != '1')
	{
		data->coor_char[1]--;
		made_move(data, window);
	}
}

// gets and changes the coordinates to move to the right
static void	move_right(t_data *data, t_window *window)
{
	data->mov[0] = data->coor_char[0];
	data->mov[1] = data->coor_char[1] + 1;
	if (data->map[data->mov[0]][data->mov[1]] != '1')
	{
		data->coor_char[1]++;
		made_move(data, window);
	}
}

// check the address of the data structure and 
// redirect to change coordinates and move
void	check_direction(t_data *data, t_window *window)
{
	data->prev[0] = data->coor_char[0];
	data->prev[1] = data->coor_char[1];
	if (data->direction == 'u')
		move_up(data, window);
	else if (data->direction == 'd')
		move_down(data, window);
	else if (data->direction == 'l')
		move_left(data, window);
	else if (data->direction == 'r')
		move_right(data, window);
}
