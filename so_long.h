
#ifndef SO_LONG
# define SO_LONG

# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_map
{
	char **map;
}	t_map;

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);

int		ft_printf(char const *format, ...);

size_t	ft_len_double(char **argv);
char **deep_copy(char **original);
void	free_split(char **split);
void free_map_number(char **copy, size_t j);


int    check_map_existance(char *map);
char    *get_map(int fd);
int check_walls(char *map);
int    check_chars(char *map);
int    check_number_chars(char *map);

int check_way(char *map);

#endif