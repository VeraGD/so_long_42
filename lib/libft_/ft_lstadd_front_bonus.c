/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:35:01 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/16 16:01:19 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
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
    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);

    // print the content of the nodes
    printf("Content: %d\n", *(int*)list->content);
    printf("Content: %d\n", *(int*)list->next->content);

    // free the memory allocated for the nodes
    free(node1);
    free(node2);

    return 0;
}*/
