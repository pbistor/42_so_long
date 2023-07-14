/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:40:41 by vprieto-          #+#    #+#             */
/*   Updated: 2023/07/14 10:51:19 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(struct s_info *info, int prex, int prey)
{
	if (info->map[info->yfly][info->xfly - 1] == 48
		|| info->map[info->yfly][info->xfly - 1] == 'C')
	{
		update_moves(info);
		info->map[info->yfly][info->xfly--] = 48;
		info->map[info->yfly][info->xfly] = 'P';
		if (info->in_door)
		{
			info->map[prey][prex] = 'E';
			info->in_door = 0;
		}
	}
	else if (info->map[info->yfly][info->xfly - 1] == 'E' )
	{
		update_moves(info);
		info->in_door = 1;
		info->map[info->yfly][info->xfly--] = 48;
		info->map[info->yfly][info->xfly] = 'P';
		if (all_collected(info))
		{
			ft_printf("Congratulations, you needed %d moves!", info->moves);
			end_game(info);
		}
	}
}

void	move_right(struct s_info *info, int prex, int prey)
{
	if (info->map[info->yfly][info->xfly + 1] == 48
		|| info->map[info->yfly][info->xfly + 1] == 'C' )
	{
		update_moves(info);
		info->map[info->yfly][info->xfly++] = 48;
		info->map[info->yfly][info->xfly] = 'P';
		if (info->in_door)
		{
			info->map[prey][prex] = 'E';
			info->in_door = 0;
		}
	}
	else if (info->map[info->yfly][info->xfly + 1] == 'E')
	{
		update_moves(info);
		info->in_door = 1;
		info->map[info->yfly][info->xfly++] = 48;
		info->map[info->yfly][info->xfly] = 'P';
		if (all_collected(info))
		{
			ft_printf("Congratulations, you needed %d moves!", info->moves);
			end_game(info);
		}
	}
}

void	move_down(struct s_info *info, int prex, int prey)
{
	if (info->map[info->yfly + 1][info->xfly] == 48
		|| info->map[info->yfly +1][info->xfly] == 'C')
	{
		update_moves(info);
		info->map[info->yfly++][info->xfly] = 48;
		info->map[info->yfly][info->xfly] = 'P';
		if (info->in_door)
		{
			info->map[prey][prex] = 'E';
			info->in_door = 0;
		}
	}
	else if (info->map[info->yfly + 1][info->xfly] == 'E')
	{
		update_moves(info);
		info->in_door = 1;
		info->map[info->yfly++][info->xfly] = 48;
		info->map[info->yfly][info->xfly] = 'P';
		if (all_collected(info))
		{
			ft_printf("Congratulations, you needed %d moves!", info->moves);
			end_game(info);
		}
	}
}

void	move_up(struct s_info *info, int prex, int prey)
{
	if (info->map[info->yfly - 1][info->xfly] == 48
		|| info->map[info->yfly - 1][info->xfly] == 'C' )
	{
		update_moves(info);
		info->map[info->yfly--][info->xfly] = 48;
		info->map[info->yfly][info->xfly] = 'P';
		if (info->in_door)
		{
			info->map[prey][prex] = 'E';
			info->in_door = 0;
		}
	}
	else if (info->map[info->yfly - 1][info->xfly] == 'E')
	{
		update_moves(info);
		info->in_door = 1;
		info->map[info->yfly--][info->xfly] = 48;
		info->map[info->yfly][info->xfly] = 'P';
		if (all_collected(info))
		{
			ft_printf("Congratulations, you needed %d moves!", info->moves);
			end_game(info);
		}
	}
}

void	update_moves(struct s_info *info)
{
	info->moves++;
	ft_printf("Movements: %d\n", info->moves);
}
