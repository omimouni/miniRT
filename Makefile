# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/20 01:58:10 by omimouni          #+#    #+#              #
#    Updated: 2021/02/05 11:26:51 by omimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

debug:
	gcc ./src/**/*.c -g -lmlx -lm -framework OpenGL -framework Appkit \
	-fsanitize=address -o miniRT