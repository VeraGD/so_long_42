#include "../../so_long.h"

// Retorno fd del map si existe, si no retorno -1
static int    check_map_existance(char *map)
{
    size_t len;
    int i;
    int fd;

    len = ft_strlen(map);
    i = len - 4;
    fd = -1;
    if (map[i] == '.' && map[i + 1] == 'b')
    {
        if (map[i + 2] == 'e' && map[i + 3] == 'r')
        {
            // Meter concatenacion de maps/ ¿¿MAS FACIL USUARIO O MENOS??
            if (access(map, R_OK) == 0) // SOLO READ
                fd = open(map, O_RDONLY); // SOLO READ
        }
    }
    return (fd);
}

// Sacar todo el mapa a un char *
// cada linea del mapa se guarda con un \n, incluida la ultima
// se sacan las lineas teniendo en cuenta su tamaño, asi que rectangulo ya comprobado
/* char    *get_map(int fd)
{
    char    *line;
    char    *res;
    char    *res2;
    size_t     len;

    line = get_next_line(fd);
    if (line == NULL) // Si no hay nada en el archivo
        return (NULL);
    len = ft_strlen(line);
    res2 = ft_strjoin(" ", line);
    res = ft_strjoin(res2, "\n");
    free(line);
    free(res2);
    while (line)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        if (len == ft_strlen(line))
        {
            res = ft_strjoin(res, line);
            res = ft_strjoin(res, "\n");
            free(line);
        }
        else
            return (NULL);
    }
    return (res);
} */

char    *get_map(int fd)
{
    char    *line;
    char    *res;
    char    *temp;
    size_t  len;

    line = get_next_line(fd);
    if (line == NULL) // Si no hay nada en el archivo
        return (NULL);
    len = ft_strlen(line);
    res = ft_strjoin(line, "\n");
    free(line);
    while ((line = get_next_line(fd)) != NULL)
    {
        if (len == ft_strlen(line))
        {
            temp = ft_strjoin(res, line);
            free(res);
            res = ft_strjoin(temp, "\n");
            free(temp);
            free(line);
        }
        else
        {
            free(line);
            free(res);
            return (NULL);
        }
    }
    return (res);
}

int    check_chars(char *map)
{
    int i;

    i = 0;
    while(map[i])
    {
        if (map[i] != '1' && map[i] != '0' && map[i] != 'P')
        {
            if(map[i] != 'E' && map[i] != 'C' && map[i] != '\n')
                return (1);
        }
        i++;
    }
    return (0);
}

int    check_number_chars(char *map)
{
    int i;
    int conte;
    int contp;
    int contc;

    i = 0;
    conte = 0;
    contp = 0;
    contc = 0;
    while(map[i])
    {
        if (map[i] == 'E')
            conte += 1;
        else if (map[i] == 'P')
            contp += 1;
        else if (map[i] == 'C')
            contc += 1;
        i++;
    }
    if (conte != 1 || contp != 1 || contc == 0)
        return (1);
    return (0);
}

size_t	ft_len_double(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int aux_check_walls(char *map)
{
    int i;
    char **split;

    i = 1;
    split = ft_split(map, '\n');
    while (i < (int)ft_len_double(split) - 1)
    {
        if (split[i][0] != '1' || split[i][ft_strlen(split[i]) - 1] != '1')
        {
            free_split(split);
            return (1);
        }
        i++;
    }
    free_split(split);
    return (0);
}

int check_walls(char *map)
{
    char **split;
    int i;
    int row_length;

    split = ft_split(map, '\n');
    i = 0;
    while (i < (int)ft_len_double(split))
    {
        row_length = ft_strlen(split[i]);
        if (i == 0 || i == (int)ft_len_double(split) - 1)
        {
            int j = 0;
            while (j < row_length)
            {
                if (split[i][j] != '1')
                {
                    free_split(split);
                    return (1);
                }
                j++;
            }
        }
        i++;
    }
    return (aux_check_walls(map));
}

int     main(int argc, char **argv)
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
                if (check_chars(map) == 0 && check_number_chars(map) == 0 && check_walls(map) == 0)
                {
                        ft_printf("%s\n", map);
                }
                else
                    ft_printf("Error\n");
                free(map);
            }
            else
                ft_printf("Error\n");
            
        }
        else
            ft_printf("Insert a valid map\n");
    }
    else
        ft_printf("Invalid number of arguments\n");
}

// ccw src/gnl/get_next_line.c src/gnl/get_next_line_utils.c src/error_map/check_char.c src/libft_/libft.a src/printf_/libftprintf.a