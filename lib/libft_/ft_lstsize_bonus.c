/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:35:17 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/16 15:54:37 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

/*int	main(void)
{
    t_list	*list;
    int		size;

    // create a new node with content = 42
    int data = 42;
    list = malloc(sizeof(t_list));
    if (list == NULL) {
        // handle error
        return 1;
    }
    list->content = &data;
    list->next = NULL;

    // add more nodes to the list
    int data1 = 43;
    list->next = malloc(sizeof(t_list));
    if (list->next == NULL) { // Si no se crea, es decir es NULL
        free(list);
        return 1;
    }
    list->next->content = &data1;
    list->next->next = NULL;

    // get the size of the list
    size = ft_lstsize(list);

    // print the size of the list
    printf("Size: %d\n", size);

    // free the memory allocated for the nodes
    free(list);

    return 0;
}*/
