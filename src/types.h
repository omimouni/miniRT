/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:37:29 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/30 10:00:15 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define MRT_TYPE_CAMERA	20
# define MRT_TYPE_PLANE		21

typedef	struct		s_mlx_img {
	void			*ptr;
	char			*addr;
	int				bpp;
	int				line_height;
	int				endian;
}					t_mlx_img;

typedef	struct		s_mlx {
	void			*ptr;
	void			*win;
	t_mlx_img		img;
}					t_mlx;

typedef struct		s_camera {
	t_point3		origin;
	t_vector3		normal;
	int				fov;
}					t_camera;

typedef struct		s_mrt_ray {
	t_point3		origin;
	t_vector3		direction;
}					t_mrt_ray;

typedef	struct		s_conf {
	unsigned int	errcode;
	unsigned int	height;
	unsigned int	width;
	unsigned char	is_save;
	t_generic_list	*cameras;
	t_camera		*current_camera;
	t_mlx			mlx;
} 					t_conf;

typedef struct		s_object {
	char			type;
	void			*object;
}					t_object;

typedef struct		s_color {
	double			r;
	double			g;
	double			b;
	double			alpha;
}					t_color;

typedef struct		s_plane {
	t_point3		cords;
	t_vector3		normal;
	t_color			color;
}					t_plane;
#endif
