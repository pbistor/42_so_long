/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:08:27 by vprieto-          #+#    #+#             */
/*   Updated: 2023/07/14 12:50:48 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_sprites_struct(struct s_info *info)
{
	int	w;
	int	h;

	info->wall = mlx_xpm_file_to_image(info->mlx, "./sprites/wall.xpm", &w, &h);
	info->fly = mlx_xpm_file_to_image(info->mlx, "./sprites/fly.xpm", &w, &h);
	info->floor
		= mlx_xpm_file_to_image(info->mlx, "./sprites/floor.xpm", &w, &h);
	info->poop = mlx_xpm_file_to_image(info->mlx, "./sprites/poop.xpm", &w, &h);
	info->door = mlx_xpm_file_to_image(info->mlx, "./sprites/door.xpm", &w, &h);
	if (!info->fly | !info->wall || !info->floor || !info->poop || !info->door)
		exit(1);
}

void	put_images(struct s_info *info, int y, int x)
{
	int	ix;
	int	iy;

	iy = (y + 1) * 32;
	ix = (x + 1) * 32;
	if (info->map[y][x] == 49)
		mlx_put_image_to_window(info->mlx, info->win, info->wall, ix, iy);
	else if (info->map[y][x] == 48)
		mlx_put_image_to_window(info->mlx, info->win, info->floor, ix, iy);
	else if (info->map[y][x] == 'C')
		mlx_put_image_to_window(info->mlx, info->win, info->poop, ix, iy);
	else if (info->map[y][x] == 'P')
	{
		if (info->initial_pos == 1)
			mlx_put_image_to_window(info->mlx, info->win, info->floor, ix, iy);
		mlx_put_image_to_window(info->mlx, info->win, info->fly, ix, iy);
	}
	else if (info->map[y][x] == 'E')
		mlx_put_image_to_window(info->mlx, info->win, info->door, ix, iy);
}

void	show_map(struct s_info *info)
{
	int	i;
	int	j;

	i = -1;
	while ((info->map[++i]) != 0)
	{
		j = -1;
		while (info->map[i][++j] != 0)
		{
			put_images(info, i, j);
		}
	}
	info->initial_pos = 0;
}
