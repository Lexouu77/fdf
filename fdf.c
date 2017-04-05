/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 09:43:11 by ahamouda          #+#    #+#             */
/*   Updated: 2016/04/01 04:37:15 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_file(char *file, t_img *img)
{
	if (parse_file(file, img))
	{
		ft_putstr("No such file or rights to the file: ");
		ft_putendl(file);
		close_image(img);
		return (1);
	}
	else if (check_emptiness(file))
	{
		ft_putendl("File is empty.");
		return (1);
	}
	return (0);
}

void	draw_map2(t_img *img, int z)
{
	img->x1 = img->x_save;
	img->y1 = img->y_save;
	if (img->y < img->max_y - 1)
	{
		img->x2 = (img->x - (img->y + 1)) * img->ratio;
		z = get_z(img->map[img->y + 1], img->x);
		img->y2 = (img->y + 1) * img->ratio - z * img->hei_v;
		draw_line(img);
	}
}

void	draw_map(t_img *img)
{
	int		z;

	img->y = 0;
	while (img->y < img->max_y)
	{
		img->x = 0;
		while (img->x < get_nb_digit(img->map[img->y]))
		{
			z = get_z(img->map[img->y], img->x);
			img->x1 = (img->x - img->y) * img->ratio;
			img->y1 = img->y * img->ratio - z * img->hei_v;
			img->x2 = ((img->x + 1) - img->y) * img->ratio;
			z = get_z(img->map[img->y], img->x + 1);
			img->y2 = img->y * img->ratio - z * img->hei_v;
			img->x_save = img->x1;
			img->y_save = img->y1;
			if (img->x < img->max_x - 1)
				draw_line(img);
			draw_map2(img, z);
			img->x++;
		}
		img->y++;
	}
}

int		grab_expose(t_img *img)
{
	ft_putendl("i -> Reverse it!.");
	ft_putendl("Right/Left Arrows -> Change colors.");
	ft_putendl("-/+ -> Decrease/Increase Height.");
	ft_putendl("Up/Down -> Zoom/Dezoom.");
	draw_map(img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_img	*img;

	if (check_error(argc, argv[1]))
		return (1);
	else if (!(img = init_image()))
		ft_mlx_error();
	else if (check_file(argv[1], img))
		return (1);
	else
	{
		img->is_reverted = 0;
		img->ratio = 5;
		img->hei_v = 2;
		img->col_v = 1;
		img->x_origine = WIDTH / 2 - (img->max_x / 2) * 10;
		img->y_origine = HEIGHT / 2 - (img->max_y / 2) * 10;
		img->color = mlx_get_color_value(img->mlx_ptr, WHITE);
		mlx_key_hook(img->win_ptr, grab_key, img);
		mlx_expose_hook(img->win_ptr, grab_expose, img);
		mlx_loop(img->mlx_ptr);
	}
	return (0);
}
