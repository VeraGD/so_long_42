/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:36:32 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/16 16:05:30 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*following;

	while (*lst)
	{
		following = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = following;
	}
	free(*lst);
	*lst = NULL;
}

/*void delete_int(void *data)
{
    free(data);
}

int main()
{
    // Creamos varios nodos para la lista
    t_list *lst = ft_lstnew(malloc(sizeof(int)));
    *((int *)lst->content) = 42;

    lst->next = ft_lstnew(malloc(sizeof(int)));
    *((int *)lst->next->content) = 21;

    lst->next->next = ft_lstnew(malloc(sizeof(int)));
    *((int *)lst->next->next->content) = 84;

    // Limpiamos la lista usando ft_lstclear
    ft_lstclear(&lst, delete_int);

    // Verificamos que la lista esté vacía
    if (lst == NULL)
        printf("La lista se ha limpiado correctamente.\n");
    else
        printf("Hubo un error al limpiar la lista.\n");

    return 0;
}*/
