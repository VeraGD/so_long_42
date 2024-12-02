/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:44:59 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/16 15:40:48 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}

/*void reverse_string(unsigned int index, char *c) {
    if (index == 0) {
        // Swap the first and last characters
        char temp = *c;
        *c = *(c + strlen(c) - 1);
        *(c + strlen(c) - 1) = temp;
    }
}

int main() {
    char str[] = "Hello, World!";
    //char *str = NULL;
    printf("Original string: %s\n", str);

    ft_striteri(str, reverse_string);
    printf("Reversed string: %s\n", str);

    return 0;
}*/
