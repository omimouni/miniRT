/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:37:29 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/05 09:39:10 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define MRT_TYPE_CAMERA	20
# define MRT_TYPE_PLANE		21
# define MRT_TYPE_SPHERE	22

typedef struct		s_color {
	int				r;
	int				g;
	int				b;
}					t_color;

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
	t_vector3		target;
	t_vector3		normal;
	double			fov;
	t_vector3		up;
	t_vector3		upguide;
	t_vector3		right;
	double			scene_h;
	double			scene_w;
	double			aspect_ratio;
}					t_camera;

typedef struct		s_mrt_ray {
	t_point3		origin;
	t_vector3		direction;
	size_t			px;
	size_t			py;
	t_color			color;
}					t_mrt_ray;

typedef struct		s_object {
	char			type;
	void			*object;
	t_color			color;
}					t_object;

typedef struct		s_plane {
	t_point3		cords;
	t_vector3		normal;
}					t_plane;

typedef struct		s_sphare {
	t_point3		center;
	double			diameter;
}					t_sphere;

typedef struct		s_cylinder {
	t_point3		cap;
	t_vector3		normal;
	t_color			color;
	double			diameter;
	double			height;
}					t_cylinder;

typedef	struct		s_pixel {
	t_object		*obj;
	t_point3		hitpoint;
	t_mrt_ray		*ray;
	t_vector3		normal;
	double			light_cof;
	double			t;
}					t_pixel;

typedef	struct		s_light	{
	t_point3		point;
	double			brightness;
	t_color			color;
	t_vector3		dir;
	double			angle;
	double			distance;
}					t_light;

typedef	struct		s_amblight {
	double			intensity;
	t_color			color;
}					t_amblight;

typedef	struct		s_conf {
	t_mlx			mlx;
	unsigned int	errcode;
	unsigned int	height;
	unsigned int	width;
	unsigned char	is_save;
	t_generic_list	*cameras;
	t_generic_list	*current_camera;
	t_generic_list	*objs;
	t_amblight		ambient_light;
	t_color			al_calculated;
	char			is_bonus;
	t_generic_list	*lights;
} 					t_conf;

#endif
