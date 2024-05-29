/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:12:13 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 14:07:49 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct so_map
{
	int		col;
	int		rows;
	char	**map;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
}			t_map;

typedef struct game
{
	void	*coin;
	int		fd;
	void	*empty;
	void	*exit;
	void	*none_exit;
	void	*player;
	void	*wall;
	t_map	*s_map;
	void	*mlx;
	void	*window;
	int		exit_count;
	int		player_count;
	int		count_collectable;
	char	**temp_map;
	int		collected;
	int		p_step;
}			t_game;

void		close_xpm_1(int fd_coin, int fd_empty, int fd_wall);
void		close_xpm_2(int fd_player, int fd_none_exit, int fd_exit);
void		xpm_control_1(void);
void		xpm_control_2(void);
void		file_control(char *path);
void		extent_control(char *path);
void		error_message(char *str);
void		read_map(t_game *game, char *path);
int			count_rc(t_game *game, char *path);
void		check_map(t_game *game);
void		map_corner_close_y(t_game *game, int y);
void		map_corner_close_x(t_game *game, int x);
void		map_valid(t_game *game);
void		character_valid(t_game *game, int x, int y);
void		p_map_valid(t_game *game, int x, int y);
void		character_count_check(t_game *game);
void		line_valid(t_game *game);
void		is_game_played(t_game *game);
void		flood_fill(t_game *game, int x, int y);
void		mlx_game(t_game *game);
void		get_image(t_game *game);
void		set_image(t_game *game);
void		put_check_image(t_game *game, int x, int y);
int			key_press(int keycode, t_game *game);
void		move_up(t_game *game);
void		move_left(t_game *game);
void		move_down(t_game *game);
void		move_right(t_game *game);
int			close_window(t_game *game);
void		free_map(t_game *game, char **map);
void		free_game_map(t_game *game);
void		close_map(t_game *game);
void		free_image(t_game *game);
void		finish_game(t_game *game);
void		yx_update(t_game *game);
void		map_size_cont(t_game *game);
void		first_control(char *path);
void		map_malloc(t_game *game, char *path);
void		copy_map(t_game *game, char *path);
void		main_map(t_game *game, char *path);
void		malloc_free(t_game *game, char **map);
void		free_map(t_game *game, char **map);
void		error_fd(void);
void		is_map(char *temp);
void		none_exit_chage(t_game *game);
void		path_recursive(char **map, int x, int y);
void		is_game_played(t_game *game);
void		e_map_valid(t_game *game, int x, int y);

#endif