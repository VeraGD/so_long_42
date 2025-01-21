/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:09:25 by veragarc          #+#    #+#             */
/*   Updated: 2024/12/13 16:45:36 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

static char	*fill_line_buffer(int fd, char *stash, char *buffer)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			return (NULL);
		}
		else if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (stash == NULL)
			stash = ft_strdup_gnl("");
		temp = stash;
		stash = ft_strjoin_gnl(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr_gnl(stash, '\n') != NULL)
			break ;
	}
	return (stash);
}

static char	*set_line(char *line_buf)
{
	size_t	i;
	char	*stash;

	i = 0;
	while (line_buf[i] != '\0' && line_buf[i] != '\n')
		i++;
	if (line_buf[i] == '\n')
		stash = ft_substr_gnl(line_buf, i + 1, ft_strlen_gnl(line_buf) - i - 1);
	else
		stash = NULL;
	line_buf[i] = '\0';
	if (stash && *stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		free(buffer);
		return (NULL);
	}
	if (buffer == NULL)
		return (NULL);
	line = fill_line_buffer(fd, stash, buffer);
	free (buffer);
	buffer = NULL;
	if (line == NULL)
		return (NULL);
	stash = set_line(line);
	return (line);
}
