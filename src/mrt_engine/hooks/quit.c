/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:15:16 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/17 17:19:20 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

extern	t_conf	*g_conf;

static void		mrt_quit_free_objs(void)
{
	t_generic_list	*current;
	t_generic_list	*tmp;

	current = g_conf->objs;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(((t_object *)tmp->obj)->object);
		free(tmp->obj);
		free(tmp);
	}
}

static void		mrt_quit_free(void)
{
	t_generic_list	*current;
	t_generic_list	*tmp;

	current = g_conf->cameras;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp->obj);
		free(tmp);
	}
	current = g_conf->lights;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp->obj);
		free(tmp);
	}
	mrt_quit_free_objs();
}

void			mrt_quit(void)
{
	if (!g_conf->is_save)
	{
		mlx_clear_window(g_conf->mlx.ptr, g_conf->mlx.win);
		mlx_destroy_window(g_conf->mlx.ptr, g_conf->mlx.win);
	}
	mlx_destroy_image(g_conf->mlx.ptr, g_conf->mlx.img.ptr);
	free(g_conf->mlx.ptr);
	mrt_quit_free();
	free(g_conf);
	printf("👋 Quitting !\n");
	exit(0);
}
