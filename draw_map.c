/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 18:30:25 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/13 18:31:45 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_max_x_and_y(char *file, t_img *img)
{
	char	*line;
	int		nb_digit;
	int		fd;

	img->i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (1);
	while ((img->i = (get_next_line(fd, &line))))
	{
		if (img->i == -1)
			return (1);
		nb_digit = get_nb_digit(line);
		if (nb_digit > img->max_x)
			img->max_x = nb_digit;
		img->max_y++;
	}
	close(fd);
	free(line);
	return (0);
}

t_img	*init_image(void)
{
	t_img *tmp_img;

	if ((!(tmp_img = (t_img *)malloc(sizeof(t_img)))) ||
		(!(tmp_img->mlx_ptr = mlx_init())) ||
			(!(tmp_img->win_ptr =
				mlx_new_window(tmp_img->mlx_ptr, WIDTH, HEIGHT, TITLE))))
		return (NULL);
	tmp_img->max_x = 0;
	tmp_img->max_y = 0;
	tmp_img->img_ptr = mlx_new_image(tmp_img->mlx_ptr, WIDTH, HEIGHT);
	tmp_img->pxl_ptr = mlx_get_data_addr(tmp_img->img_ptr,
			&(tmp_img->bit_per_pxl), &(tmp_img->size_line),
			&(tmp_img->endian));
	return (tmp_img);
}

void	ft_mlx_error(void)
{
	ft_putendl("Mlx-lib Error.");
	exit(-1);
}

void	close_image(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
}

int		get_nb_digit(char *str)
{
	int	i;
	int	nb_digit;

	i = 0;
	nb_digit = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == 45)
		{
			nb_digit++;
			while ((ft_isdigit(str[i]) || str[i] == 45) && str[i + 1])
				i++;
		}
		i++;
	}
	return (nb_digit);
}
