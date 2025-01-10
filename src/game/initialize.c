#include "../../so_long.h"

// returns as int * the coordinates in which the character is located (rows, columns)
static void *find_char(char **map, char to_find)
{
    int i;
    int j;
    int *coor;

    i = 0;
    coor = (int *)malloc(2 * sizeof(int));
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == to_find)
            {
                coor[0] = i;
                coor[1] = j;
                return (coor);
            }
            j++;
        }
        i++;
    }
    free(coor);
    return (NULL);
}

// returns as int * the size of the map (rows, columns)
static int  *get_size_map(char **map)
{
    int *size;

    size = (int *)malloc(2 * sizeof(int));
    size[0] = (int)ft_len_double(map);
    size[1] = (int)ft_strlen(map[0]);
    return (size);
}

mlx_image_t *load_texture(mlx_t *mlx, char *file)
{
    mlx_texture_t *texture;
    mlx_image_t *imagen;

	texture = mlx_load_png(file);
	if (!texture)
        error();
    imagen = mlx_texture_to_image(mlx, texture);
	if (!imagen)
    {
        mlx_delete_texture(texture);
        error();
    }
    mlx_delete_texture(texture);
    return (imagen);
}

t_window    *initiaize_window(int *size)
{
    t_window  *window;
    mlx_t *mlx;

    window = (t_window *)malloc(sizeof(t_window));
    mlx = mlx_init(size[1] * 100, size[0] * 100, "So long", true);
	if (!mlx)
        error();
    window->mlx = mlx;
    window->wall = load_texture(mlx, "imgs/arbusto_b.png");
    window->collectible = load_texture(mlx, "imgs/adn_b.png");
    window->player_l = load_texture(mlx, "imgs/vaca_l.png");
    window->player_r = load_texture(mlx, "imgs/vaca_r.png");
    window->player_u = load_texture(mlx, "imgs/vaca_u.png");
    window->player_d = load_texture(mlx, "imgs/vaca_d.png");
    window->floor = load_texture(mlx, "imgs/fondo_b.png");
    window->exit_close = load_texture(mlx, "imgs/puerta_c.png");
    window->exit_open = load_texture(mlx, "imgs/puerta_a.png");
    window->exit_open_open = load_texture(mlx, "imgs/exit_oo.png");
    window->exit_player = load_texture(mlx, "imgs/over_exit.png");
    return (window);
}

int *generate_zeros()
{
    int *res;

    res = (int *)malloc(2 * sizeof(int));
    res[0] = 0;
    res[1] = 0;
    return (res);
}

// initializes the basic data structure of the map
t_data    *initiaize_data(char *map)
{
    char    **map_double;
    char    **map_copy;
    t_data  *data;

    map_double = ft_split(map, '\n');
    map_copy = deep_copy(map_double);
    data = (t_data *)malloc(sizeof(t_data));
    data->map = map_copy;
    data->collectionables = find_collectionables(map_copy);
    data->coor_char = find_char(map_copy, 'P');
    data->size = get_size_map(map_copy);
    data->window = initiaize_window(data->size);
    data->coor_exit = find_char(map_copy, 'E');
    data->direction = 'i';
    data->exit_status = 'c';
    data->upper_exit = 'n';
    data->mov = generate_zeros();
    data->prev = generate_zeros();
    free_split(map_double);
    return (data);
}



