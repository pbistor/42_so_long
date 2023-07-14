/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:10:50 by vprieto-          #+#    #+#             */
/*   Updated: 2023/07/14 12:18:32 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(struct s_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((info->map[i]) != 0)
	{
		while (info->map[i][j] != 0)
		{
			if (info->map[i][j] == 'P')
			{
				info->xfly = j;
				info->yfly = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	info->in_door = 0;
}

void	copy_map(struct s_info *info, int fd)
{
	int	i;

	i = 0;
	info->map[i] = get_next_line(fd);
	info->is_visited[i] = ft_strdup(info->map[i]);
	while (info->map[i])
	{
		info->map[++i] = get_next_line(fd);
		if (info->map[i] != 0)
			info->is_visited[i] = ft_strdup(info->map[i]);
	}
}

void	initialize_map(struct s_info *info, int i)
{
	info->is_visited = (char **)ft_calloc((i + 2), sizeof(char *));
	if (!info->is_visited)
	{
		exit(1);
	}
	info->map = (char **)ft_calloc((i + 2), sizeof(char *));
	if (!info->map)
	{
		free(info->is_visited);
		exit(1);
	}
	info->initial_pos = 1;
}

void	parse_map(struct s_info *info, char *arg)
{
	int		fd;
	int		i;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nNo se ha podido abrir el mapa.\n");
		exit(1);
	}
	i = calc_map_rows(fd);
	initialize_map(info, i);
	close(fd);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nUnable to open map.\n");
		exit(1);
	}
	copy_map(info, fd);
	find_player(info);
	close(fd);
}

int	calc_map_rows(int fd)
{
	int		i;
	char	*a;

	i = 0;
	a = get_next_line(fd);
	if (a == 0)
	{
		ft_printf("Error\nEmpty map.");
		exit(1);
	}
	while (a != 0)
	{
		free(a);
		a = get_next_line(fd);
		i++;
	}
	return (i);
}
