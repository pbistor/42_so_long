/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:29:10 by vprieto-          #+#    #+#             */
/*   Updated: 2023/07/14 12:17:49 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(struct s_info *info)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(info->map[i]);
	if (check_map_components(info) == 0)
		return (0);
	if (check_min_components(info) == 0)
		return (0);
	if (check_is_rectangle(info, len) == 0)
		return (0);
	if (check_map_walls(info, len) == 0)
		return (0);
	search_path(info, info->yfly, info->xfly);
	return (check_valid_path(info));
}

int	check_map_walls(struct s_info *info, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (info->map[i] != 0)
	{
		if (info->map[i][0] != 49 || info->map[i][len - 2] != 49)
		{
			ft_printf("Error\nThere's a problem involving vertical walls.\n");
			return (0);
		}
		i++;
	}
	len = i;
	i = 0;
	while (info->map[0][i] != '\n' && info->map[0][i] != 0)
	{	
		if (info->map[0][i] != 49 || info->map[len - 1][i++] != 49)
		{
			ft_printf("Error\nThere's a problem involving horizontal walls.\n");
			return (0);
		}
	}
	return (1);
}

int	check_min_components(struct s_info *info)
{
	int	i;
	int	j;
	int	flags[3];

	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	i = -1;
	j = -1;
	while ((info->map[++i]) != 0)
	{
		while (info->map[i][++j] != 0)
		{
			check_character(info->map[i][j], flags);
		}
		j = -1;
	}
	if (flags[1] != 1 || flags[0] != 1 || flags[2] == 0)
	{
		ft_printf("Error\nThe number of components is wrong.\n");
		return (0);
	}
	return (1);
}

int	check_is_rectangle(struct s_info *info, size_t len)
{
	int	i;

	i = 0;
	info->width = len;
	while (info->map[i] != 0)
	{
		if (ft_strlen(info->map[i]) != len)
		{
			ft_printf("Error\nMap is not a rectangle.\n");
			return (0);
		}
		i++;
	}
	info->height = i;
	return (1);
}

int	check_map_components(struct s_info *info)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while ((info->map[i]) != 0)
	{
		while (info->map[i][j] != 0 && info->map[i][j] != '\n')
		{
			if (info->map[i][j] != 'E' && info->map[i][j] != 'C' &&
					info->map[i][j] != 49 && info->map[i][j] != 48 &&
					info->map[i][j] != 'P')
			{
				ft_printf("Error\nMap contains wrong characters.\n");
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
