/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:23:08 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 13:18:13 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	yx_update(t_game *game)
{
	if (game->s_map->map[game->s_map->p_y][game->s_map->p_x] != 'E')
	{
		game->s_map->map[game->s_map->p_y][game->s_map->p_x] = '0';
	}
	game->p_step++;
	ft_printf("move steps: %d\n", game->p_step);
}

void	move_left(t_game *game)
{
	if (game->s_map->map[game->s_map->p_y][game->s_map->p_x - 1] == '1')
		return ;
	else if (game->s_map->map[game->s_map->p_y][game->s_map->p_x - 1] == '0')
	{
		yx_update(game);
		game->s_map->map[game->s_map->p_y][game->s_map->p_x - 1] = 'P';
		game->s_map->p_x--;
	}
	else if (game->s_map->map[game->s_map->p_y][game->s_map->p_x - 1] == 'C')
	{
		yx_update(game);
		game->s_map->map[game->s_map->p_y][game->s_map->p_x - 1] = 'P';
		game->s_map->p_x--;
		game->collected++;
	}
	else if (game->s_map->map[game->s_map->p_y][game->s_map->p_x - 1] == 'E')
	{
		if (game->collected == game->count_collectable)
			finish_game(game);
		yx_update(game);
		game->s_map->map[game->s_map->p_y][game->s_map->p_x - 1] = 'P';
		game->s_map->p_x--;
		none_exit_chage(game);
	}
}

void	move_right(t_game *game)
{
	if (game->s_map->map[game->s_map->p_y][game->s_map->p_x + 1] == '1')
		return ;
	else if (game->s_map->map[game->s_map->p_y][game->s_map->p_x + 1] == '0')
	{
		yx_update(game);
		game->s_map->map[game->s_map->p_y][game->s_map->p_x + 1] = 'P';
		game->s_map->p_x++;
	}
	else if (game->s_map->map[game->s_map->p_y][game->s_map->p_x + 1] == 'C')
	{
		yx_update(game);
		game->s_map->map[game->s_map->p_y][game->s_map->p_x + 1] = 'P';
		game->s_map->p_x++;
		game->collected++;
	}
	else if (game->s_map->map[game->s_map->p_y][game->s_map->p_x + 1] == 'E')
	{
		if (game->collected == game->count_collectable)
			finish_game(game);
		yx_update(game);
		game->s_map->map[game->s_map->p_y][game->s_map->p_x + 1] = 'P';
		game->s_map->p_x++;
		none_exit_chage(game);
	}
}

void	malloc_free(t_game *game, char **map)
{
	free(map);
	free(game->s_map);
	free(game);
}
