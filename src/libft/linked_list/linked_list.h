/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:41:27 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/25 22:59:59 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct				s_generic_list {
	void					*obj;
	struct s_generic_list	*next;
}							t_generic_list;

t_generic_list	*ft_glist_init(void);
t_generic_list	*ft_glist_add(t_generic_list *list, void *obj);
#endif