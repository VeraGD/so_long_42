#include "../so_long.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"

void close_window(void* param)
{
    t_data *data = (t_data*)param;
    if (data && data->window && data->window->mlx)
    {
        mlx_terminate(data->window->mlx);
        ft_printf("You closed the game");
        exit(EXIT_SUCCESS);
    }
}

int     main(int argc, char **argv)
{
    int     fd;
    char    *map;
    t_data *data;
    t_window    *window;

    map = 0;
    if (argc == 2)
    {
        fd = check_map_existance(argv[1]);
        if (fd != -1)
        {
            map = get_map(fd);
            if (map)
            {
                if (check_chars(map) == 0 && check_number_chars(map) == 0 && check_walls(map) == 0 && check_way(map) == 0)
                {
                        data = initiaize_data(map);
                        print_map(data);
                        ft_printf("GAME START\n");
                        free(map);
                        window = data->window;
                        rendering(data, window);
                        mlx_key_hook(window->mlx, handle_input, data);
                        mlx_close_hook(window->mlx, close_window, data);
                        mlx_loop(window->mlx);
                        free_data(data); // YA ESTOY LIBERANDO WINDOW CON ESTO (DOS WINDOW)
                        mlx_terminate(window->mlx);
                }
                else
                {
                    ft_printf("Error\n");
                    free(map);
                }
            }
            else
            {
                ft_printf("Error\n");
                free(map);
            }
        }
        else
            ft_printf("Insert a valid map\n");
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
