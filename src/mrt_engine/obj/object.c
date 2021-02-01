/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:29:03 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/01 18:32:29 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_object	*object_new(char type, void *obj)
{
	t_object	*tmp;

	tmp = malloc(sizeof(t_object));
	tmp->type = type;
	tmp->object = obj;
	return (tmp);
}
