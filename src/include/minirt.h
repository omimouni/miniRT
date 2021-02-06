/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:13:52 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/06 10:23:46 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define WINDOW_TITLE "miniRT"

# define MRT_RENDER_WINDOW	10
# define MRT_RENDER_IMAGE	11

# ifdef __MACH__
#  define MRT_KEY_ESC 			53
#	define MRT_KEY_NUM5			87
#	define MRT_KEY_NUM4			86
#	define MRT_KEY_NUM6			88
#	define MRT_KEY_NUM2			84
#	define MRT_KEY_NUM8			91
#	define MRT_KEY_NUM7			89
#	define MRT_KEY_NUM9			92
#	define MRT_KEY_ARROW_UP		126
#	define MRT_KEY_ARROW_DOWN	125
#	define MRT_KEY_ARROW_LEFT	123
#	define MRT_KEY_ARROW_RIGHT	124
#endif

# ifdef __linux__
# 	define MRT_KEY_ESC			65307
#	define MRT_KEY_NUM5			65437
#	define MRT_KEY_NUM4			65430
#	define MRT_KEY_NUM6			65432
#	define MRT_KEY_NUM2			65433
#	define MRT_KEY_NUM8			65431
#	define MRT_KEY_NUM7			65429
#	define MRT_KEY_NUM9			65434
#	define MRT_KEY_ARROW_UP		65362
#	define MRT_KEY_ARROW_DOWN	65364
#	define MRT_KEY_ARROW_LEFT	65361
#	define MRT_KEY_ARROW_RIGHT	65363
#endif

# include <math.h>
# include <mlx.h>
# include "libft.h"
# include "mrt_types.h"

void			mrt_init(void);
void			mrt_parser(int argc, char **argv);
void			mrt_error(void);

void			mrt_render(void);
void			mrt_render_loop(size_t swidth, size_t width ,
	size_t sheight, size_t height);

void			mrt_hooks(void);
void			mrt_window_loop(void);
void			mrt_save_image(void);
void			mrt_put_pixel(size_t x, size_t y, t_color color);

t_mrt_ray		*mrt_ray_init(t_point3 orig);
t_point3		mrt_ray_point(double t, t_mrt_ray *ray);
void			mrt_raytrace(t_mrt_ray	*ray);
void			mrt_ray_update(t_mrt_ray **ray, size_t px, size_t py);

int				mrt_key_handler(int keycode);
void			mrt_update_window(void);

t_camera		*camera_new(t_point3 origin, t_vector3 normal, int fov);

int				hex_from_rgba(int r, int g, int b);
int				hex_from_color(t_color color);
t_color			color_from_rgb(int r, int g, int b);
t_color			color_from_hex(int hex);
t_color			color_add(t_color a, t_color b);
t_color			color_multi(t_color a, double con);

t_amblight		ambiant_light_new(double i, int r, int g, int b);

t_camera		*camera_new_(t_point3 origin, t_vector3 target, int fov);
void			camera_calc(t_camera *camera);
t_camera		*mrt_current_camera(void);
double			camera_position_x(size_t px);
double			camera_position_y(size_t py);
t_object		*object_new(char type, void *obj);

t_object		*plane_new(t_point3 cords, t_vector3 normal, t_color color);
double			mrt_intersect_plane(t_mrt_ray *ray, t_object *obj);
double			mrt_plane_cast_shadow(t_pixel *p, t_object *obj, t_light *light);

t_pixel			*pixel_new(double t, t_object *obj, t_mrt_ray *ray);
void			mrt_pixel_update(t_pixel *p, double t, t_mrt_ray *ray,
				t_object *obj);

t_object		*sphere_new(t_point3 center, double diameter, t_color color);
double			mrt_intersect_sphere_equation(t_mrt_ray *ray, t_sphere *s,
				double *t1, double *t2);
double			mrt_intersect_sphere(t_mrt_ray *ray, t_object *obj);
double			mrt_sphere_cast_shadow(t_pixel *p, t_object *obj,
				t_light *light);

t_light			*light_new(t_point3 point, double brightness, t_color color);
void			mrt_light_points(t_pixel *pixel);
void			mrt_light_ambiant(t_pixel *pixel);
#endif