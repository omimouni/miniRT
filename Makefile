# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/20 01:58:10 by omimouni          #+#    #+#              #
#    Updated: 2021/02/20 15:00:28 by omimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRC  =	src/mrt_engine/bmp.c\
				src/mrt_engine/save.c\
				src/mrt_engine/camera.c\
				src/mrt_engine/window.c\
				src/mrt_engine/hooks/cam_rotate.c\
				src/mrt_engine/hooks/cam_translate.c\
				src/mrt_engine/hooks/hooks.c\
				src/mrt_engine/hooks/keyhook.c\
				src/mrt_engine/render/light/light.c\
				src/mrt_engine/render/light/light_calc.c\
				src/mrt_engine/render/loop.c\
				src/mrt_engine/render/raytrace.c\
				src/mrt_engine/render/render.c\
				src/mrt_engine/utils/color.c\
				src/mrt_engine/utils/color_calc.c\
				src/mrt_engine/utils/pixel.c\
				src/mrt_engine/utils/ray.c\
				src/mrt_engine/utils/utils.c\
				src/mrt_engine/obj/cylinder/cylinder.c\
				src/mrt_engine/obj/square.c\
				src/mrt_engine/obj/cylinder/cylinder_calc.c\
				src/mrt_engine/obj/cylinder/cylinder_cap.c\
				src/mrt_engine/obj/cylinder/cylinder_normal.c\
				src/mrt_engine/obj/plane/plane.c\
				src/mrt_engine/obj/plane/plane_uv.c\
				src/mrt_engine/obj/sphere/sphere.c\
				src/mrt_engine/obj/sphere/sphere_uv.c\
				src/mrt_engine/obj/triangle/triangle.c\
				src/mrt_engine/obj/triangle/triangle_calc.c\
				src/mrt_parser/error.c\
				src/mrt_parser/init.c\
				src/mrt_parser/parse_cons.c\
				src/mrt_parser/parse_obj.c\
				src/mrt_parser/parser.c\
				src/mrt_parser/utils.c\
				src/main.c

LIBFT = libft.a

FLAGS = -Wall -Werror -Wextra -lmlx -lX11 -lXext -lm\
					-I$(abspath src/include)\
					-I$(abspath src/libft/include)

all: $(NAME)

$(LIBFT):
	make -C $(abspath src/libft)
	cp $(abspath src/libft/libft.a) $(abspath src/)

$(NAME): $(LIBFT)
	gcc $(SRC) $(FLAGS) src/libft.a -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf src/libft.a
	make -C $(abspath src/libft) fclean

re: fclean all