/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 09:11:58 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/13 18:46:57 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "libmx2/mlx.h"
# include <stdio.h>
# define TITLE "ahamouda's 42-FDF"
# define WIDTH 1400
# define HEIGHT 720
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define BLACK 0x000000
# define PURPLE 0x800080
# define CYAN 0x00ffff

typedef struct		s_img
{
	int				i;
	int				is_reverted;
	int				hei_v;
	int				ratio;
	int				col_v;
	int				x;
	int				y;
	double			x1;
	double			y1;
	int				dist;
	double			x_save;
	double			y_save;
	double			x2;
	double			y2;
	int				x_origine;
	int				y_origine;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				max_x;
	int				max_y;
	char			*pxl_ptr;
	int				bit_per_pxl;
	int				size_line;
	int				endian;
	unsigned int	color;
	char			**map;
}					t_img;

int					get_z(char *str, int x);
int					get_nb_digit(char *str);
int					get_max_x_and_y(char *file, t_img *img);

int					parse_file(char *file, t_img *img);

int					check_error(int nb_arg, char *file);
int					check_file(char *file, t_img *img);
int					check_emptiness(char *file);
int					is_full_dot(char *file);

void				close_image(t_img *img);

t_img				*init_image();

int					grab_key(int keycode, t_img *img);
void				grab_key2(int keycode, t_img *img);
void				grab_key3(int keycode, t_img *img);
int					grab_expose(t_img *img);

void				get_color(t_img *img);
void				draw_line(t_img *img);
void				draw_pixel(t_img *img, int x, int y);
void				draw_map(t_img *img);
void				draw_map2(t_img *img, int z);
void				clear_map(t_img *img);

void				ft_mlx_error();

#endif
