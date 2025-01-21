/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:30:23 by veragarc          #+#    #+#             */
/*   Updated: 2025/01/16 12:30:27 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "MLX42/include/MLX42/MLX42.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_counter
{
	mlx_image_t	*tens_0;
	mlx_image_t	*tens_1;
	mlx_image_t	*tens_2;
	mlx_image_t	*tens_3;
	mlx_image_t	*tens_4;
	mlx_image_t	*tens_5;
	mlx_image_t	*tens_6;
	mlx_image_t	*tens_7;
	mlx_image_t	*tens_8;
	mlx_image_t	*tens_9;
	mlx_image_t	*units_0;
	mlx_image_t	*units_1;
	mlx_image_t	*units_2;
	mlx_image_t	*units_3;
	mlx_image_t	*units_4;
	mlx_image_t	*units_5;
	mlx_image_t	*units_6;
	mlx_image_t	*units_7;
	mlx_image_t	*units_8;
	mlx_image_t	*units_9;
}	t_counter;

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	**player_l;
	mlx_image_t	**player_r;
	mlx_image_t	**player_u;
	mlx_image_t	**player_d;
	mlx_image_t	*collectible;
	mlx_image_t	*exit_close;
	mlx_image_t	*exit_open;
	mlx_image_t	**exit_l;
	mlx_image_t	**exit_r;
	mlx_image_t	**exit_u;
	mlx_image_t	**exit_d;
	mlx_image_t	*ovni; //only bonus
	t_counter	*counter; //only bonus
}	t_window;

typedef struct s_data
{
	int			collectionables;
	int			*coor_char; //row, column character
	int			*coor_exit; //row, column exit
	char		**map;
	int			*size; //len rows, len columns
	char		direction; // i->inicio, u->up, d->down, l->left, r-<right
	char		exit_status; // c->close, o->open
	char		upper_exit; // y->yes, n->no HA PASADO POR ENCIMA DE LA CASITA
	int			*prev; //row, colum previous
	int			*mov; //row, colum movement
	int			cont; //counter
	int			ev; // evolution
	int			count_col;
	int			*collec_ev; // collectionables to evolution
	t_window	*window;
}	t_data;

size_t		ft_strlen_gnl(const char *str);
size_t		ft_strlen(const char *str);
char		*ft_strdup_gnl(const char *src);
char		*ft_strdup(const char *src);
char		*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char		*ft_strjoin_gnl(char const *s1, char const *s2);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr_gnl(const char *s, int c);
char		**ft_split(char const *s, char c);
char		*get_next_line(int fd);

int			ft_printf(char const *format, ...);

size_t		ft_len_double(char **argv);
char		**deep_copy(char **original);
void		error(void);
void		free_split(char **split);
void		free_map_number(char **copy, size_t j);

int			check_map_existance(char *map);
char		*get_map(int fd);
int			check_walls(char *map);
int			check_chars(char *map);
int			check_number_chars(char *map);
int			check_way(char *map);

int			find_collectionables(char **map);
void		*find_char(char **map, char to_find);
int			*get_size_map(char **map);
mlx_image_t	*load_texture(mlx_t *mlx, char *file);
int			*generate_zeros(void);
t_data		*initiaize_data(char *map);

void		rendering(t_data *data, t_window *window);

void		draw_floor(t_window *window, t_data *data);
void		draw_player(t_window *window, t_data *data);

void		check_direction(t_data *data, t_window *window);

void		made_move(t_data *data, t_window *window);

void		handle_input(mlx_key_data_t key_data, void *param);

void		free_window(t_window *window);
void		free_data(t_data *data);

char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
int			*get_collect_eval(char **map);
void		render_counter(t_data *data, t_window *window, t_counter *counter);
void		exit_game(t_window *window, t_data *data);
void		exit_game_over(t_window *window, t_data *data);
void		close_window(void *param);
void		free_doble_image(mlx_image_t **img, t_window *window);

#endif
