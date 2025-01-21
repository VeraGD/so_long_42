/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:43:09 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/16 15:51:20 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

static char	*memory_trim(size_t str, size_t nd)
{
	char	*res;

	res = (char *)malloc(nd - str + 1 + 1);
	if (res == NULL)
		return (NULL);
	return (res);
}

static int	start(size_t str, size_t nd, char const *s1, char const *set)
{
	while (str < nd && ft_strchr(set, s1[str]) != NULL)
		str++;
	return (str);
}

static int	end(size_t str, size_t nd, char const *s1, char const *set)
{
	while (str < nd && ft_strchr(set, s1[nd]) != NULL)
		nd--;
	return (nd);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	str;
	size_t	nd;
	char	*res;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	nd = ft_strlen(s1) - 1;
	str = 0;
	str = start(str, nd, s1, set);
	nd = end(str, nd, s1, set);
	if (str >= nd)
	{
		str = 0;
		nd = -1;
	}
	res = memory_trim(str, nd);
	i = 0;
	while (i < nd - str + 1)
	{
		res[i] = s1[str + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*int main()
{
    const char *str = "  hHola! h";
    const char *set = " h!";
    printf("Original string:%s\n", str);
    printf("mi fuct %s\n", ft_strtrim(str, set));
    //free(trimmed_str);
}*/
