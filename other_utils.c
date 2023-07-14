/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:45:53 by vprieto-          #+#    #+#             */
/*   Updated: 2023/07/14 12:02:17 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_character(char c, int *flags)
{
	if (c == 'P')
		flags[0]++;
	if (c == 'E')
		flags[1]++;
	if (c == 'C')
		flags[2]++;
}

int	all_collected(struct s_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((info->map[i]) != 0)
	{
		while (info->map[i][j] != 0)
		{
			if (info->map[i][j] == 'C')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	ft_free(struct s_info *info)
{
	int	i;

	i = -1;
	while ((info->map[++i]) != 0)
	{
		free(info->is_visited[i]);
		free(info->map[i]);
	}
	free(info->map);
	free(info->is_visited);
	free_images(info);
	mlx_destroy_window(info->mlx, info->win);
}

void	ft_free_map(struct s_info *info)
{
	int	i;

	i = -1;
	while ((info->map[++i]) != 0)
	{
		free(info->is_visited[i]);
		free(info->map[i]);
	}
	free(info->map);
	free(info->is_visited);
	exit(1);
}

void	free_images(struct s_info *info)
{
	mlx_destroy_image(info->mlx, info->wall);
	mlx_destroy_image(info->mlx, info->floor);
	mlx_destroy_image(info->mlx, info->door);
	mlx_destroy_image(info->mlx, info->fly);
	mlx_destroy_image(info->mlx, info->poop);
}
