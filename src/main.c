#include "../so_long.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"

/* void close_window(void *param)
{
    t_data *data = (t_data *)param;
    ft_printf("Ventana cerrada.\n");
    free_data(data); // Libera todos los recursos
    mlx_terminate(data->window->mlx); // Termina la conexión con MLX
    exit(0);
} */

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
                        ft_printf("%s\n", map);
                        ft_printf("entra");
                        data = initiaize_data(map);
                        /* ft_printf("size: %d, %d\n", data->size[0], data->size[1]);
                        ft_printf("coord: %d, %d\n", data->coor_char[0], data->coor_char[1]);
                        ft_printf("coord: %d, %d\n", data->coor_exit[0], data->coor_exit[1]);
                        ft_printf("collectionales: %d\n", data->collectionables);
                        ft_printf("first_line: %s\n", data->map[0]); */
                        window = data->window;
                        rendering(data, window);
                        mlx_key_hook(window->mlx, handle_input, data);
                        //mlx_hook(window->mlx, 17, 0, close_window, data);
                        mlx_loop(window->mlx);
                        free(map);
                        /* free_split(data->map);
                        free(data->coor_char);
                        free(data->size);
                        free(data);
                        free_window(window); */
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
