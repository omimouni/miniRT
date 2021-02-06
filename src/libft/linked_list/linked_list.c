/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:14:50 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/06 09:56:27 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/linked_list.h"

t_generic_list	*ft_glist_init(void)
{
	return (NULL);
}

t_generic_list	*ft_glist_add(t_generic_list *list, void *obj)
{
	t_generic_list	*node;
	t_generic_list	*current;

	node = malloc(sizeof(t_generic_list));
	node->obj = obj;
	node->next = NULL;
	if (list == NULL)
		list = node;
	else
	{
		current = list;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
	return (list);
}
