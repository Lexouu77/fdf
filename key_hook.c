/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 18:32:08 by ahamouda          #+#    #+#             */
/*   Updated: 2016/04/01 04:37:17 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_color(t_img *img)
{
	if (img->col_v == 0)
		img->col_v = 7;
	if (img->col_v == 8)
		img->col_v = 1;
	if (img->col_v == 1)
		img->color = mlx_get_color_value(img->mlx_ptr, WHITE);
	if (img->col_v == 2)
		img->color = mlx_get_color_value(img->mlx_ptr, RED);
	if (img->col_v == 3)
		img->color = mlx_get_color_value(img->mlx_ptr, BLUE);
	if (img->col_v == 4)
		img->color = mlx_get_color_value(img->mlx_ptr, GREEN);
	if (img->col_v == 5)
		img->color = mlx_get_color_value(img->mlx_ptr, YELLOW);
	if (img->col_v == 6)
		img->color = mlx_get_color_value(img->mlx_ptr, CYAN);
	if (img->col_v == 7)
		img->color = mlx_get_color_value(img->mlx_ptr, PURPLE);
}

void	grab_key3(int keycode, t_img *img)
{
	if (keycode == 34)
	{
		img->is_reverted = (img->is_reverted) ? 0 : 1;
		clear_map(img);
		img->ratio = -img->ratio;
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (keycode == 69)
	{
		clear_map(img);
		if (img->hei_v < 150)
			img->hei_v++;
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (keycode == 124)
	{
		img->col_v++;
		get_color(img);
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
}

void	grab_key2(int keycode, t_img *img)
{
	if (keycode == 123)
	{
		img->col_v--;
		get_color(img);
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (keycode == 78)
	{
		clear_map(img);
		if (img->hei_v > -150)
			img->hei_v--;
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (keycode == 53)
	{
		close_image(img);
		exit(0);
	}
}

int		grab_key(int keycode, t_img *img)
{
	if (keycode == 126)
	{
		clear_map(img);
		(img->is_reverted) ? img->ratio-- : img->ratio++;
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	if (keycode == 125)
	{
		clear_map(img);
		!(img->is_reverted) ? img->ratio-- : img->ratio++;
		draw_map(img);
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	}
	grab_key2(keycode, img);
	grab_key3(keycode, img);
	return (0);
}
