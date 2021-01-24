/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:14:50 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/24 21:52:18 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_generic_list	*ft_gnr_list_init(void *obj)
{
	t_generic_list	*node;

	node = malloc(sizeof(t_generic_list));
	node->obj = obj;
	node->next = NULL;
	return (node);
}

t_generic_list	*ft_gnr_list_add(t_generic_list *list, void *obj)
{
	t_generic_list	*node;
	t_generic_list	*current;

	current = list;
	if (current == NULL)
		current = ft_gnr_list_init(obj);
	else
	{
		node = malloc(sizeof(t_generic_list));
		node->obj = obj;
		node->next = NULL;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
	return (list);
}

void			ft_gnr_list_free(t_generic_list	*list)
{
	t_generic_list	*current;
	t_generic_list	*tmp;

	current = list;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}
