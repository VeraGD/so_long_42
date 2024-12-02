/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:44:20 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/16 15:55:51 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*char ft_char_transform(unsigned int index, char c) {
    // Example transformation function that returns the character 'x'
    // for odd indices and the original character for even indices.
    return (index % 2 == 0) ? c : 'x';
}

int main() {
    const char *input_str = "Hello, World!";
	//const char *input_str = NULL;
    char *transformed_str = ft_strmapi(input_str, ft_char_transform);
    printf("Transformed string: %s\n", transformed_str);
    free(transformed_str);

    return 0;
}*/
