#include "../../so_long.h"

void map_print(t_data *data)
{
    if (data->map[data->prev[0]][data->prev[1]] == 'E')
    {
        data->map_print[data->prev[0]][data->prev[1]] = 'E';
        data->map_print[data->mov[0]][data->mov[1]] = 'P';
    }
    else
    {
        data->map_print[data->prev[0]][data->prev[1]] = '0';
        data->map_print[data->mov[0]][data->mov[1]] = 'P';
    }
}

void draw_floor(t_window *window, t_data *data)
{
    int col;
    int row;

    col = data->prev[1] * 100;
    row = data->prev[0] * 100;
    if (data->upper_exit == 'y' && data->map[data->prev[0]][data->prev[1]] == 'E')
        mlx_image_to_window(window->mlx, window->exit_close, col, row);
    else if (data->upper_exit == 'y' && data->map[data->prev[0]][data->prev[1]] == '0')
        mlx_image_to_window(window->mlx, window->floor, col, row);
    else
        mlx_image_to_window(window->mlx, window->floor, col, row);
}

void draw_player_over(t_window *window, t_data *data, int row, int col)
{
    if (data->direction == 'r')
        mlx_image_to_window(window->mlx, window->exit_r, col, row);
    else if (data->direction == 'l')
        mlx_image_to_window(window->mlx, window->exit_l, col, row);
    else if (data->direction == 'u')
        mlx_image_to_window(window->mlx, window->exit_u, col, row);
    else if (data->direction == 'd')
        mlx_image_to_window(window->mlx, window->exit_d, col, row);
}

void draw_player(t_window *window, t_data *data)
{
    int col;
    int row;

    col = data->mov[1] * 100;
    row = data->mov[0] * 100;
    if (data->upper_exit == 'y' && data->map[data->mov[0]][data->mov[1]] == 'E')
        draw_player_over(window, data, row, col);
    else if (data->direction == 'r')
        mlx_image_to_window(window->mlx, window->player_r, col, row);
    else if (data->direction == 'l')
        mlx_image_to_window(window->mlx, window->player_l, col, row);
    else if (data->direction == 'd')
        mlx_image_to_window(window->mlx, window->player_d, col, row);
    else if (data->direction == 'u')
        mlx_image_to_window(window->mlx, window->player_u, col, row);
    map_print(data);

}

/* void valid_move(t_data *data, int x, int y)
{
    if (data->map[x][y] != '1')
    {
        if (data->map[x][y] == 'C')
        {
            data->collectionables--;
            if (data->collectionables == 0)
            {
                // cambio salida
            }
        }
        if (data->map[x][y] == 'E' && data->collectionables != 0)
        {
            // salida mas personaje
        }
        if (data->map[x][y] == 'E' && data->collectionables == 0)
        {
            //acabo el juego
        }
        else
    }
    draw_player(data->window, data);
} */

/* void handle_input(mlx_key_data_t key_data, void *param)
{
    t_window *window;
    t_data *data = (t_data *)param; 

    window = data->window;
    if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)  // 'ESC'
    {
        mlx_close_window(window->mlx);
        window->mlx = NULL;
    }
    draw_floor(window, data);
    if ((key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP) && key_data.action == MLX_PRESS)  // 'W'
    {
        if (data->map[data->coor_char[0] - 1][data->coor_char[1]] != '1')
        {
            data->map[data->coor_char[0]][data->coor_char[1]] = '0';
            if (data->map[data->coor_char[0] - 1][data->coor_char[1]] == 'C')
            {
                data->collectionables--;
                data->map[data->coor_char[0] - 1][data->coor_char[1]] = '0';
            }
            ft_printf("collectionables: %d\n", data->collectionables);
            data->coor_char[0]--;
        }
    }
    else if ((key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN) && key_data.action == MLX_PRESS)  // 'S'
    {
        if (data->map[data->coor_char[0] + 1][data->coor_char[1]] != '1')
        {
            data->map[data->coor_char[0]][data->coor_char[1]] = '0';
            if (data->map[data->coor_char[0] + 1][data->coor_char[1]] == 'C')
            {
                data->collectionables--;
                data->map[data->coor_char[0] + 1][data->coor_char[1]] = '0';
            }
            ft_printf("collectionables: %d\n", data->collectionables);
            data->coor_char[0]++;
        }
    }
    else if ((key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT) && key_data.action == MLX_PRESS)  // 'A'
    {
        if (data->map[data->coor_char[0]][data->coor_char[1] - 1] != '1')
        {
            data->map[data->coor_char[0]][data->coor_char[1]] = '0';
            if (data->map[data->coor_char[0]][data->coor_char[1] - 1] == 'C')
            {
                data->collectionables--;
                data->map[data->coor_char[0]][data->coor_char[1] - 1] = '0';
            }
            ft_printf("collectionables: %d\n", data->collectionables);
            data->coor_char[1]--;
        }
    }
    else if ((key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT) && key_data.action == MLX_PRESS)  // 'D'
    {
        if (data->map[data->coor_char[0]][data->coor_char[1] + 1] != '1')
        {
            data->map[data->coor_char[0]][data->coor_char[1]] = '0';
            if (data->map[data->coor_char[0]][data->coor_char[1] + 1] == 'C')
            {
                data->collectionables--;
                data->map[data->coor_char[0]][data->coor_char[1] + 1] = '0';
            }
            ft_printf("collectionables: %d\n", data->collectionables);
            data->coor_char[1]++;
        }
    }
    ft_printf("%s\n", data->map[0]);
    ft_printf("%s\n", data->map[1]);
    ft_printf("%s\n", data->map[2]);
    ft_printf("%s\n", data->map[3]);
    ft_printf("%s\n", data->map[4]);
    ft_printf("\n");
    draw_player(window, data);
} */

/* void handle_input(mlx_key_data_t key_data, void *param)
{
    t_window *window;
    t_data *data = (t_data *)param; 

    window = data->window;
    if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)  // 'ESC'
    {
        mlx_close_window(window->mlx);
        window->mlx = NULL;
    }
    draw_floor(window, data);
    if ((key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP) && key_data.action == MLX_PRESS)  // 'W'
    {
        if (data->map[data->coor_char[0] - 1][data->coor_char[1]] != '1')
            data->coor_char[0]--;
    }
    else if ((key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN) && key_data.action == MLX_PRESS)  // 'S'
    {
        if (data->map[data->coor_char[0] + 1][data->coor_char[1]] != '1')
            data->coor_char[0]++;
    }
    else if ((key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT) && key_data.action == MLX_PRESS)  // 'A'
    {
        if (data->map[data->coor_char[0]][data->coor_char[1] - 1] != '1')
            data->coor_char[1]--;
    }
    else if ((key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT) && key_data.action == MLX_PRESS)  // 'D'
    {
        if (data->map[data->coor_char[0]][data->coor_char[1] + 1] != '1')
            data->coor_char[1]++;
    }
    draw_player(window, data);
} */

void exit_game(t_window *window)
{
    mlx_close_window(window->mlx);
    window->mlx = NULL;
    ft_printf("YOU WIN!\n");
    exit(0);
}

void made_move(t_data *data, t_window *window)
{

    if (data->map[data->mov[0]][data->mov[1]] == 'C')
    {
        data->collectionables--;
        if (data->collectionables == 0)
        {
            if (mlx_image_to_window(window->mlx, window->exit_open, data->coor_exit[1] * 100, data->coor_exit[0] * 100) < 0)
                error();
            data->exit_status = 'o';
        }
        draw_floor(window, data);
        draw_player(window, data);
    }
    if (data->map[data->mov[0]][data->mov[1]] == 'E')
    {
        if (data->exit_status == 'c')
            data->upper_exit = 'y';
        else
            exit_game(window);
        draw_floor(window, data);
        draw_player(window, data);
    }
    else
    {
        draw_floor(window, data);
        draw_player(window, data);
        data->upper_exit = 'n';
    }
}

void move_up(t_data *data, t_window *window)
{
    data->mov[0] = data->coor_char[0] - 1;
    data->mov[1] = data->coor_char[1];
    if (data->map[data->mov[0]][data->mov[1]] != '1')
    {
        data->coor_char[0]--;
        made_move(data, window);
    }
}

void move_down(t_data *data, t_window *window)
{
    data->mov[0] = data->coor_char[0] + 1;
    data->mov[1] = data->coor_char[1];
    if (data->map[data->mov[0]][data->mov[1]] != '1')
    {
        data->coor_char[0]++;
        made_move(data, window);
    }
}

void move_left(t_data *data, t_window *window)
{
    data->mov[0] = data->coor_char[0];
    data->mov[1] = data->coor_char[1] - 1;
    if (data->map[data->mov[0]][data->mov[1]] != '1')
    {
        data->coor_char[1]--;
        made_move(data, window);
    }
}

void move_right(t_data *data, t_window *window)
{
    data->mov[0] = data->coor_char[0];
    data->mov[1] = data->coor_char[1] + 1;
    if (data->map[data->mov[0]][data->mov[1]] != '1')
    {
        data->coor_char[1]++;
        made_move(data, window);
    }
}

void print_map(t_data *data)
{
    int len;
    int i;

    len = ft_len_double(data->map_print);
    i = 0;
    while (i < len)
    {
        ft_printf("%s\n", data->map_print[i]);
        i++;
    }
}

void check_direction(t_data *data, t_window *window)
{
    data->prev[0] = data->coor_char[0];
    data->prev[1] = data->coor_char[1];
    data->cont++;
    if (data->direction == 'u')
        move_up(data, window);
    else if (data->direction == 'd')
        move_down(data, window);
    else if (data->direction == 'l')
        move_left(data, window);
    else if (data->direction == 'r')
        move_right(data, window);
    print_map(data);
    ft_printf("Moves: %d\n", data->cont);
}

void check_exit(mlx_key_data_t key_data, t_window *window)
{
    if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)  // 'ESC'
    {
        mlx_close_window(window->mlx);
        window->mlx = NULL;
        ft_printf("You closed the game");
        exit(0);
    }
}

void handle_input(mlx_key_data_t key_data, void *param)
{
    t_window *window;
    t_data *data = (t_data *)param;

    window = data->window;
    check_exit(key_data, window);
    if ((key_data.key == MLX_KEY_W || key_data.key == MLX_KEY_UP) && key_data.action == MLX_PRESS)  // 'W'
    {
        data->direction = 'u';
        check_direction(data, window);
    }
    else if ((key_data.key == MLX_KEY_S || key_data.key == MLX_KEY_DOWN) && key_data.action == MLX_PRESS)  // 'S'
    {
        data->direction = 'd';
        check_direction(data, window);
    }
    else if ((key_data.key == MLX_KEY_A || key_data.key == MLX_KEY_LEFT) && key_data.action == MLX_PRESS)  // 'A'
    {
        data->direction = 'l';
        check_direction(data, window);
    }
    else if ((key_data.key == MLX_KEY_D || key_data.key == MLX_KEY_RIGHT) && key_data.action == MLX_PRESS)  // 'D'
    {
        data->direction = 'r';
        check_direction(data, window);
    }
}


