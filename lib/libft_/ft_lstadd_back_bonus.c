/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:45:36 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/16 16:03:30 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst != NULL || new != NULL)
	{
		last = ft_lstlast(*lst);
		if (last)
			last->next = new;
		else
			*lst = new;
	}
}

/*int	main(void)
{
    t_list	*list;
    t_list	*node1;
    t_list	*node2;
    int		data1;
    int		data2;

    // create a new node with content = 42
    data1 = 42;
    node1 = malloc(sizeof(t_list));
    if (node1 == NULL) {
        // handle error
        return 1;
    }
    node1->content = &data1;
    node1->next = NULL;

    // create a new node with content = 84
    data2 = 84;
    node2 = malloc(sizeof(t_list));
    if (node2 == NULL) {
        // handle error
        return 1;
    }
    node2->content = &data2;
    node2->next = NULL;

    // add the nodes to the list
    list = NULL;
    ft_lstadd_back(&list, node1);
    ft_lstadd_back(&list, node2);

    // print the content of the nodes
    printf("Content: %d\n", *(int*)list->content);
    printf("Content: %d\n", *(int*)list->next->content);

    // free the memory allocated for the nodes
    free(node1);
    free(node2);

    return 0;
}*/
