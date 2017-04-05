/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 18:28:48 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/13 18:46:17 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		parse_file(char *file, t_img *img)
{
	char	*line;
	int		fd;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (get_max_x_and_y(file, img))
		return (1);
	if (!(fd = open(file, O_RDONLY)))
		return (1);
	if (!(img->map = (char **)malloc(sizeof(char *) * img->max_y)))
		ft_malloc_error();
	while ((img->i = get_next_line(fd, &line)) && y != img->max_y)
	{
		if (img->i == -1)
			return (1);
		if (!(img->map[y] = ft_strnew(img->max_x)))
			ft_malloc_error();
		img->map[y] = line;
		y++;
	}
	free(line);
	return (0);
}

int		is_full_dot(char *file)
{
	int		i;
	size_t	k;

	i = 0;
	k = 0;
	while (file[i])
	{
		if (file[i] == '.' || file[i] == '/')
			k++;
		i++;
	}
	return (k == ft_strlen(file) ? (0) : (1));
}

int		check_error(int nb_arg, char *file)
{
	if (nb_arg > 2)
	{
		ft_putendl("Only one file is accepted by FdF");
		return (1);
	}
	else if (nb_arg != 2 || file == 0 || (!is_full_dot(file)))
	{
		ft_putendl("No file specified.");
		return (1);
	}
	return (0);
}

int		check_emptiness(char *file)
{
	int		fd;
	char	*line;

	if (!(fd = open(file, O_RDONLY)))
		return (1);
	if (get_next_line(fd, &line) == 0)
		return (1);
	else
	{
		close(fd);
		return (0);
	}
}
