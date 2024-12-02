/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:05:36 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/22 11:31:12 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	j;
	size_t	d;

	i = 0;
	count = 0;
	d = 0;
	if (*s == '\0')
		return (0);
	j = ft_strlen(s);
	while (i < j)
	{
		if (s[i] == c && s[i + 1] != c && i != j - 1)
			count++;
		else if (s[i] != c && i == 0)
			count++;
		else if (s[i] != c)
			d++;
		i++;
	}
	if (d == j)
		return (1);
	return (count);
}

static char	**book_memory(int count, size_t len)
{
	char	**str;
	int		i;
	int		j;

	str = (char **)malloc((count + 1) * 8);
	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (i < count)
	{
		str[i] = (char *)malloc(len + 1);
		if (str[i] == NULL)
		{
			while (j < i)
			{
				free(str[j]);
				j++;
			}
			free(str);
			return (NULL);
		}
		i++;
	}
	return (str);
}

static char	**aux_split(char const *s, char **res, char c)
{
	size_t	i;
	size_t	j;
	int		cont;

	i = 0;
	j = 0;
	cont = 0;
	while (j < ft_strlen(s))
	{
		if (s[j] != c && s[j + 1] != c)
		{
			res[cont][i] = s[j];
			i++;
		}
		else if (s[j] != c)
		{
			res[cont][i] = s[j];
			i++;
			res[cont][i] = '\0';
			cont++;
			i = 0;
		}
		j++;
	}
	return (res);
}

static char	**zero_words(size_t len)
{
	char	**str;

	str = (char **)malloc((2) * 8);
	if (str == NULL)
		return (NULL);
	str[0] = (char *)malloc(len + 1);
	if (str[0] == NULL)
	{
		free(str[0]);
		free(str);
		return (NULL);
	}
	str[0] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**def;
	char	**res;
	size_t	w;

	if (s == NULL)
		return (NULL);
	w = count_words(s, c);
	if (w == 0)
		return (zero_words(ft_strlen(s)));
	res = book_memory(w, ft_strlen(s));
	res[w] = NULL;
	def = aux_split(s, res, c);
	return (def);
}

/*int	main(void)
{
	//const char str[] = "    ";
	
	//const char *str = NULL;
	//char c = ' ';
	char **r = ft_split("     a b c d        e", ' ');
    size_t i = 0;
    size_t j = count_words("     a b c d        e    ", ' ');
    printf("Numero de palabras: %d\n", (int)j);
	//printf(" %s\n", r[i]);
    while (i < j)
    {
        printf(" %s\n", r[i]);
        i++;
    }
}*/
