/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:54:12 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/21 12:54:30 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

// putnbr, if n > 99 return nn
char	*ft_putnbr_count(int n)
{
	int		i;
	char	*res;

	i = 10;
	res = (char *)malloc(2 * sizeof(char));
	if (n > 9 && n < 100)
	{
		res[0] = n / 10 + '0';
		n = n % i;
		res[1] = n + '0';
	}
	else if (n > 0 && n < 10)
	{
		res[0] = '0';
		res[1] = n + '0';
	}
	else if (n > 99)
	{
		res[0] = 'n';
		res[1] = 'n';
	}
	return (res);
}

// print units of the counter
static void	render_units(t_data *data, t_window *window, t_counter *counter)
{
	char	*count;

	count = ft_putnbr_count(data->cont);
	if (count[1] == '0')
		mlx_image_to_window(window->mlx, counter->units_0, 100, 0);
	else if (count[1] == '1')
		mlx_image_to_window(window->mlx, counter->units_1, 100, 0);
	else if (count[1] == '2')
		mlx_image_to_window(window->mlx, counter->units_2, 100, 0);
	else if (count[1] == '3')
		mlx_image_to_window(window->mlx, counter->units_3, 100, 0);
	else if (count[1] == '4')
		mlx_image_to_window(window->mlx, counter->units_4, 100, 0);
	else if (count[1] == '5')
		mlx_image_to_window(window->mlx, counter->units_5, 100, 0);
	else if (count[1] == '6')
		mlx_image_to_window(window->mlx, counter->units_6, 100, 0);
	else if (count[1] == '7')
		mlx_image_to_window(window->mlx, counter->units_7, 100, 0);
	else if (count[1] == '8')
		mlx_image_to_window(window->mlx, counter->units_8, 100, 0);
	else if (count[1] == '9')
		mlx_image_to_window(window->mlx, counter->units_9, 100, 0);
	free(count);
}

// if the moves > 99 no counter is founded and it prints the moves
static void	render_floor_if(t_data *data, t_window *window, char *count)
{
	if (count[0] == 'n')
	{
		mlx_image_to_window(window->mlx, window->wall, 0, 0);
		mlx_image_to_window(window->mlx, window->wall, 100, 0);
		ft_printf("Moves: %d\n", data->cont);
	}
	free(count);
}

// print the counter tens + units
void	render_counter(t_data *data, t_window *window, t_counter *counter)
{
	char	*count;

	count = ft_putnbr_count(data->cont);
	if (count[0] == '0')
		mlx_image_to_window(window->mlx, counter->tens_0, 0, 0);
	else if (count[0] == '1')
		mlx_image_to_window(window->mlx, counter->tens_1, 0, 0);
	else if (count[0] == '2')
		mlx_image_to_window(window->mlx, counter->tens_2, 0, 0);
	else if (count[0] == '3')
		mlx_image_to_window(window->mlx, counter->tens_3, 0, 0);
	else if (count[0] == '4')
		mlx_image_to_window(window->mlx, counter->tens_4, 0, 0);
	else if (count[0] == '5')
		mlx_image_to_window(window->mlx, counter->tens_5, 0, 0);
	else if (count[0] == '6')
		mlx_image_to_window(window->mlx, counter->tens_6, 0, 0);
	else if (count[0] == '7')
		mlx_image_to_window(window->mlx, counter->tens_7, 0, 0);
	else if (count[0] == '8')
		mlx_image_to_window(window->mlx, counter->tens_8, 0, 0);
	else if (count[0] == '9')
		mlx_image_to_window(window->mlx, counter->tens_9, 0, 0);
	render_floor_if(data, window, count);
	render_units(data, window, counter);
}
