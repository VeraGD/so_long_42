/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:35:34 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/16 15:35:41 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int	main(void)
{
    t_list	*list;
    t_list	*last;

    // create a new node with content = 42
    int data = 42;
    list = malloc(sizeof(t_list));
    if (list == NULL) {
        // handle error
        return 1;
    }
    list->content = &data;
    list->next = NULL;

    int data1 = 43;
    list->next = malloc(sizeof(t_list));
    if (list->next == NULL) { // Si no se crea, es decir es NULL
        free(list);
        return 1;
    }
    list->next->content = &data1;
    list->next->next = NULL;

    // get the last node in the list
    last = ft_lstlast(list);
    if (last != NULL)
        printf("Content: %d\n", *(int*)list->content);
    else
        printf("NULL");
    return 0;
}*/
