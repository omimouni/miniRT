/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:01:35 by omimouni          #+#    #+#             */
/*   Updated: 2021/01/26 12:18:44 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BMP_H
# define FT_BMP_H
# include <stdlib.h>

typedef	struct		s_bmp_file_header {
	size_t			file_size;
	size_t			header_size;
	size_t			header_offset;
	
	size_t			image_height;
	size_t			image_width;

}					t_bmp_file_header;

typedef struct		s_bmp_pixel {
	int				red;
	int				green;
	int				blue;
}					t_bmp_pixel;
#endif
