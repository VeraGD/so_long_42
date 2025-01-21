/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:51:15 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/21 12:51:29 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

// game closes if you win
void	exit_game(t_window *window, t_data *data)
{
	(void)window;
	free_data(data);
	ft_printf("YOU WIN!\n");
	exit(0);
}

// game closes if you touch an enemy
void	exit_game_over(t_window *window, t_data *data)
{
	(void)window;
	free_data(data);
	ft_printf("GAME OVER!\n");
	exit(0);
}

// if you close the upper x window it closes without giving error
void	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data && data->window && data->window->mlx)
	{
		free_data(data);
		ft_printf("You closed the game\n");
		exit(0);
	}
}
