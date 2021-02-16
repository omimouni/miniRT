# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 17:02:42 by omimouni          #+#    #+#              #
#    Updated: 2021/02/16 18:05:16 by omimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_maths/vector3_op.c\
			ft_maths/vector3.c\
			linked_list/linked_list.c\
			string/ft_putchar_fd.c\
			string/ft_putstr_fd.c\
			string/ft_split.c\
			string/ft_strchr.c\
			string/ft_strdup.c\
			string/ft_strjoin.c\
			string/ft_strlen.c\
			string/ft_strncmp.c\
			string/ft_substr.c\
			utils/clamp.c\
			utils/ft_atoi.c\
			utils/ft_parsefloat.c\
			utils/gnl.c

OBJ = $(notdir $(SRC:.c=.o))

FLAGS = -Wall -Werror -Wextra -lm -c -I$(abspath include)

all: $(NAME)

$(NAME): $(SRC)
	@gcc $(SRC) $(FLAGS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "LIBFT: Build successful !"

clean:
	@rm -rf $(OBJ)
	@echo "LIBFT: clean !"
fclean: clean
	@rm -rf $(NAME)
	@echo "LIBFT: fclean!"

re: fclean all