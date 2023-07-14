/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:20:17 by vprieto-          #+#    #+#             */
/*   Updated: 2023/07/14 16:58:47 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(struct s_info *info)
{
	ft_free(info);
	exit(0);
	return (0);
}

int	change_map(int keycode, struct s_info *info)
{
	int	prex;
	int	prey;

	prey = info->yfly;
	prex = info->xfly;
	if (keycode == 13)
		move_up(info, prex, prey);
	else if (keycode == 1)
		move_down(info, prex, prey);
	else if (keycode == 0)
		move_left(info, prex, prey);
	else if (keycode == 2)
		move_right(info, prex, prey);
	else if (keycode == 53)
	{
		end_game(info);
	}
	show_map(info);
	return (1);
}

int	main(int argc, char **argv)
{
	struct s_info	info;

	if (argc != 2)
	{
		ft_printf("Error\nArguments number is wrong.\n");
		return (-1);
	}
	info.mlx = mlx_init();
	info.moves = 0;
	fill_sprites_struct(&info);
	parse_map(&info, argv[1]);
	if (!check_map(&info))
	{
		ft_free_map(&info);
	}
	info.win = mlx_new_window(info.mlx, (info.width + 1) * 32,
			(info.height + 2) * 32, "Fly Game");
	show_map(&info);
	mlx_key_hook(info.win, change_map, &info);
	mlx_hook(info.win, 17, 0, end_game, &info);
	mlx_loop(info.mlx);
	exit(0);
}
