/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:57:16 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/21 12:57:18 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

// Free memory of double pointer
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

// Free memory from double pointer indicating
// the index at which to start freeing memory (from back to front).
void	free_map_number(char **copy, size_t j)
{
	size_t	k;

	k = 0;
	while (k < j)
	{
		free(copy[k]);
		k++;
	}
	free(copy);
}

// free an mlx_image_t **
void	free_doble_image(mlx_image_t **img, t_window *window)
{
	int	i;

	i = 4;
	while (i < 4)
	{
		mlx_delete_image(window->mlx, img[i]);
		i++;
	}
	free(img);
}
