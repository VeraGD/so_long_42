/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_existance_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:23:38 by veragarc          #+#    #+#             */
/*   Updated: 2024/12/13 16:40:15 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// If the map file exists, returns its fd (only checks read permissions).
int	check_map_existance(char *map)
{
	size_t	len;
	int		i;
	int		fd;

	len = ft_strlen(map);
	i = len - 4;
	fd = -1;
	if (map[i] == '.' && map[i + 1] == 'b')
	{
		if (map[i + 2] == 'e' && map[i + 3] == 'r')
		{
			if (access(map, R_OK) == 0)
				fd = open(map, O_RDONLY);
		}
	}
	return (fd);
}

// Auxiliary function to get_map, it saves in a char * 
// variable what is read from the map line by line.
static char	*aux_get_map(char *line, char *res)
{
	char	*temp;

	temp = ft_strjoin(res, line);
	free(res);
	res = ft_strjoin(temp, "\n");
	free(temp);
	free(line);
	return (res);
}

// Auxiliary function of c, checks if the flag of 
// the longitude is 1, the map is not rectangular.
void	*aux_aux_get_map(char *res, int flag)
{
	if (flag == 1)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

// Read the map and save it in a char *, checking if it is rectangular.
// A line break is also saved at the end, 
// creating a last empty line (then with the split it is removed).
char	*get_map(int fd)
{
	char	*line;
	char	*res;
	size_t	len;
	int		flag;

	flag = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line);
	res = ft_strjoin(line, "\n");
	free(line);
	line = "A";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (len != ft_strlen(line))
			flag = 1;
		res = aux_get_map(line, res);
	}
	return (aux_aux_get_map(res, flag));
}
