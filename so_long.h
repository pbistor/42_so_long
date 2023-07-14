/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:34:28 by vprieto-          #+#    #+#             */
/*   Updated: 2023/07/14 12:12:02 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "./libft/libft.h"

struct s_info{
	void	*mlx;
	void	*win;
	void	*fly;
	void	*wall;
	void	*door;
	char	**map;
	char	**is_visited;
	void	*floor;
	void	*poop;
	int		moves;
	int		xfly;
	int		yfly;
	int		in_door;
	int		initial_pos;
	int		width;
	int		height;
} s_info;

char	*ft_strdup(const char *s1);
void	find_player(struct s_info *info);
void	copy_map(struct s_info *info, int fd);
void	initialize_map(struct s_info *info, int i);
void	parse_map(struct s_info *info, char *arg);
int		calc_map_rows(int fd);
void	fill_sprites_struct(struct s_info *info);
char	*ft_strdup(const char *s1); //USAR EL DE LA LIBFT!
int		change_map(int keycode, struct s_info *info);
void	move_up(struct s_info *info, int prex, int prey);
void	move_down(struct s_info *info, int prex, int prey);
void	move_right(struct s_info *info, int prex, int prey);
void	move_left(struct s_info *info, int prex, int prey);
void	update_moves(struct s_info *info);
int		close_win(int keycode, struct s_info *info);
void	ft_free(struct s_info *info);
void	show_map(struct s_info *info);
void	put_images(struct s_info *info, int y, int x);
int		check_valid_path(struct s_info *info);
int		check_map(struct s_info *info);
int		check_map_walls(struct s_info *info, int len);
int		check_min_components(struct s_info *info);
void	check_character(char c, int *flags);
int		check_is_rectangle(struct s_info *info, size_t len);
int		check_map_components(struct s_info *info);
void	search_path(struct s_info *info, int y, int x);
int		all_collected(struct s_info *info);
int		end_game(struct s_info *info);
void	free_images(struct s_info *info);
void	ft_free_map(struct s_info *info);

#endif
