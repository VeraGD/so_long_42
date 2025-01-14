#include "../../so_long.h"

static void aux_rendering(int i, int j, t_window *window, t_data *data)
{
    if (data->map[i][j] == 'C')
    {
        if (mlx_image_to_window(window->mlx, window->collectible, j * 100, i * 100) < 0)
            error();
    }
    else if (data->map[i][j] == '0')
    {
        if (mlx_image_to_window(window->mlx, window->floor, j * 100, i * 100) < 0)
            error();
    }
    else if (data->map[i][j] == 'P')
    {
        if (mlx_image_to_window(window->mlx, window->player_d, j * 100, i * 100) < 0)
            error();
    }
}

void rendering(t_data *data, t_window *window)
{
    int i;
    int j;

    i = 0;
    while(data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if (data->map[i][j] == '1')
            {
                if (mlx_image_to_window(window->mlx, window->wall, j * 100, i * 100) < 0)
                    error();
            }
            else if (data->map[i][j] == 'E')
            {
                if (mlx_image_to_window(window->mlx, window->exit_close, j * 100, i * 100) < 0)
                    error();
            }
            aux_rendering(i, j, window, data);
            j++;
        }
        i++;
    }
}
