/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 18:35:07 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/13 19:00:39 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_z(char *s, int n)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[k])
	{
		if (ft_isdigit(s[k]) || s[k] == 45)
		{
			i++;
			if (i == n + 1)
			{
				return (ft_atoi(s + k));
			}
			while ((ft_isdigit(s[k]) || s[k] == 45) && s[k + 1])
				k++;
		}
		k++;
	}
	return (0);
}

void	draw_pixel(t_img *img, int x, int y)
{
	if (x + img->x_origine < WIDTH && y + img->y_origine < HEIGHT &&
			x + img->x_origine > 0 && y + img->y_origine > 0)
		*(unsigned int*)(img->pxl_ptr + ((img->bit_per_pxl / 8 *
			(img->x_origine + x)) + img->size_line *
				(img->y_origine + y))) = img->color;
}

void	draw_line(t_img *img)
{
	double	m;
	double	p;

	img->i = 0;
	img->dist = img->x2 - img->x1;
	m = (img->y2 - img->y1) / (img->x2 - img->x1);
	p = img->y1 - m * img->x1;
	if (m <= 1 && m >= -1)
		while (img->i != img->dist)
		{
			draw_pixel(img, img->x1 + img->i, img->y1);
			img->x1 < img->x2 ? img->i++ : img->i--;
			img->x1 < img->x2 ? (img->y1 += m) : (img->y1 -= m);
		}
	else
	{
		m = (img->x2 - img->x1) / (img->y2 - img->y1);
		img->dist = img->y2 - img->y1;
		while (img->i != img->dist)
		{
			draw_pixel(img, img->x1, img->y1 + img->i);
			img->y1 < img->y2 ? img->i++ : img->i--;
			img->y1 < img->y2 ? (img->x1 += m) : (img->x1 -= m);
		}
	}
}

void	clear_map(t_img *img)
{
	int				x;
	int				y;
	unsigned int	c;

	y = 0;
	c = img->color;
	img->color = mlx_get_color_value(img->mlx_ptr, BLACK);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			*(unsigned int*)(img->pxl_ptr + ((img->bit_per_pxl / 8 *
				(x++)) + img->size_line * (y))) = img->color;
		y++;
	}
	img->color = c;
}
