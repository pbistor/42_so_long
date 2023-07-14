/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_verify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:14:57 by vprieto-          #+#    #+#             */
/*   Updated: 2023/07/14 12:17:55 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_path(struct s_info *info, int y, int x)
{
	if (info->is_visited[y][x] != '1' && info->is_visited[y][x] != 'V')
	{
		info->is_visited[y][x] = 'V';
		search_path(info, y + 1, x);
		search_path(info, y, x + 1);
		search_path(info, y - 1, x);
		search_path(info, y, x - 1);
	}
}

int	check_valid_path(struct s_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((info->is_visited[i]) != 0)
	{
		while (info->is_visited[i][j] != 0)
		{
			if (info->map[i][j] == 'E' && info->is_visited[i][j] != 'V')
			{
				ft_printf("Error\nThere's no valid path.\n");
				return (0);
			}
			if (info->map[i][j] == 'C' && info->is_visited[i][j] != 'V')
			{
				ft_printf("Error\nThere's no valid path.\n");
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
