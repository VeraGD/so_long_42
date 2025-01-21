/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:14:34 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/16 16:15:18 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// if you close the upper x window it closes without giving error
static void	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data && data->window && data->window->mlx)
	{
		free_data(data);
		ft_printf("You closed the game\n");
		exit(EXIT_SUCCESS);
	}
}

// aux main, when the map is correct, it process the movements
static void	aux_main(char *map)
{
	t_data		*data;
	t_window	*window;

	data = initiaize_data(map);
	ft_printf("GAME START\n");
	free(map);
	window = data->window;
	rendering(data, window);
	mlx_key_hook(window->mlx, handle_input, data);
	mlx_close_hook(window->mlx, close_window, data);
	mlx_loop(window->mlx);
	free_data(data);
	mlx_terminate(window->mlx);
}

// another aux to check the errors
static void	aux_aux_main(char *map, int fd)
{
	if (fd != -1)
	{
		map = get_map(fd);
		if (map)
		{
			if (check_chars(map) == 0 && check_number_chars(map) == 0
				&& check_walls(map) == 0 && check_way(map) == 0)
				aux_main(map);
			else
			{
				ft_printf("Error in the map\n");
				free(map);
			}
		}
		else
		{
			ft_printf("Error map is empty\n");
			free(map);
		}
	}
	else
		ft_printf("Insert a valid map\n");
}

// main
int	main(int argc, char **argv)
{
	int		fd;
	char	*map;

	map = 0;
	if (argc == 2)
	{
		fd = check_map_existance(argv[1]);
		aux_aux_main(map, fd);
	}
	else
		ft_printf("Invalid number of arguments\n");
}

// The memory leaks came from the MLX42 library
/* int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(1920, 1080, "Title", true);
	mlx_terminate(mlx);
	return (0);
} */
