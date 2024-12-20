#include "../so_long.h"

void     main_error(int argc, char **argv)
{
    int     fd;
    char    *map;

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
                        free(map);
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

// ccw src/gnl/get_next_line.c src/gnl/get_next_line_utils.c src/error_map/check_char.c src/libft_/libft.a src/printf_/libftprintf.a
