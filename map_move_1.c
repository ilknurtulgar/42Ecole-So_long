/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:16:09 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 13:18:17 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(t_game *game)
{
	ft_printf("move steps: %d\n", ++game->p_step);
	ft_printf("<<congratulations you finished the game honey >>\n");
	close_window(game);
}

void	none_exit_chage(t_game *game)
{
	set_image(game);
	game->s_map->map[game->s_map->e_y][game->s_map->e_x] = 'E';
}

void	move_up(t_game *game)
{
	if (game->s_map->map[game->s_map->p_y - 1][game->s_map->p_x] == '1')
		return ;
	else if (game->s_map->map[game->s_map->p_y - 1][game->s_map->p_x] == '0')
	{
		yx_update(game);
		game->s_map->map[game->s_map->p_y - 1][game->s_map->p_x] = 'P';
		game->s_map->p_y--;
	}
	else if (game->s_map->map[game->s_map->p_y - 1][game->s_map->p_x] == 'C')
	{
		yx_update(game);
		game->s_map->map[game->s_map->p_y - 1][game->s_map->p_x] = 'P';
		game->s_map->p_y--;
		game->collected++;
	}
	else if (game->s_map->map[game->s_map->p_y - 1][game->s_map->p_x] == 'E')
	{
		if (game->collected == game->count_collectable)
			finish_game(game);
		yx_update(game);
		game->s_map->map[game->s_map->p_y - 1][game->s_map->p_x] = 'P';
		game->s_map->p_y--;
		none_exit_chage(game);
	}
}

void	move_down(t_game *game)
{
	if (game->s_map->map[game->s_map->p_y + 1][game->s_map->p_x] == '1')
		return ;
	else if (game->s_map->map[game->s_map->p_y + 1][game->s_map->p_x] == '0')
	{
		yx_update(game);
		game->s_map->map[game->s_map->p_y + 1][game->s_map->p_x] = 'P';
		game->s_map->p_y++;
	}
	else if (game->s_map->map[game->s_map->p_y + 1][game->s_map->p_x] == 'C')
	{
		yx_update(game);
		game->s_map->map[game->s_map->p_y + 1][game->s_map->p_x] = 'P';
		game->collected++;
		game->s_map->p_y++;
	}
	else if (game->s_map->map[game->s_map->p_y + 1][game->s_map->p_x] == 'E')
	{
		if (game->collected == game->count_collectable)
			finish_game(game);
		yx_update(game);
		game->s_map->map[game->s_map->p_y + 1][game->s_map->p_x] = 'P';
		game->s_map->p_y++;
		none_exit_chage(game);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 53)
		close_window(game);
	else if (keycode == 13)
		move_up(game);
	else if (keycode == 0)
		move_left(game);
	else if (keycode == 1)
		move_down(game);
	else if (keycode == 2)
		move_right(game);
	set_image(game);
	return (0);
}
