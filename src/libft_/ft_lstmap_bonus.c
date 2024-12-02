/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:37:19 by veragarc          #+#    #+#             */
/*   Updated: 2024/09/16 16:04:51 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*aux;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (res == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		aux = ft_lstnew(f(lst->content));
		if (aux == NULL)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, aux);
		lst = lst->next;
	}
	return (res);
}

/*void *duplicate(void *content)
{
    int *new_value = (int *)malloc(sizeof(int));
    if (!new_value)
        return NULL;
    *new_value = *(int *)content * 2; // Duplicamos el valor
    return (void *)new_value;
}

// Función para liberar la memoria del 
//contenido de un nodo (en este caso, un entero)
void delete_content(void *content)
{
    free(content);
}

int main()
{
    // Creamos la lista original con algunos valores enteros
    t_list *original = ft_lstnew(malloc(sizeof(int)));
    *((int *)original->content) = 1;

    ft_lstadd_back(&original, ft_lstnew(malloc(sizeof(int))));
    *((int *)original->next->content) = 2;

    ft_lstadd_back(&original, ft_lstnew(malloc(sizeof(int))));
    *((int *)original->next->next->content) = 3;

    ft_lstadd_back(&original, ft_lstnew(malloc(sizeof(int))));
    *((int *)original->next->next->next->content) = 4;

    // Aplicamos ft_lstmap para duplicar cada valor
    t_list *mapped_list = ft_lstmap(original, duplicate, delete_content);

    // Imprimimos los valores de la lista original y la lista mapeada
    t_list *temp = original;
    printf("Lista original:\n");
    while (temp)
    {
        printf("%d\n", *((int *)temp->content));
        temp = temp->next;
    }

    temp = mapped_list;
    printf("\nLista mapeada (duplicada):\n");
    while (temp)
    {
        printf("%d\n", *((int *)temp->content));
        temp = temp->next;
    }

    // Limpiamos ambas listas
    ft_lstclear(&original, delete_content);
    ft_lstclear(&mapped_list, delete_content);

    return 0;
}*/
