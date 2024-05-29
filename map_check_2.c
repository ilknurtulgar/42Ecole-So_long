/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:10:00 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 14:00:16 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_map_valid(t_game *game, int x, int y)
{
	game->player_count++;
	game->s_map->p_x = x;
	game->s_map->p_y = y;
}

void	e_map_valid(t_game *game, int x, int y)
{
	game->s_map->e_x = x;
	game->s_map->e_y = y;
}

void	character_count_check(t_game *game)
{
	if ((game->count_collectable < 1) || (game->exit_count != 1)
		|| (game->player_count != 1))
	{
		error_message("failure character count");
		free_game_map(game);
	}
}

void	character_valid(t_game *game, int x, int y)
{
	if ((game->s_map->map[y][x] != 'P') && (game->s_map->map[y][x] != 'C')
		&& (game->s_map->map[y][x] != 'E') && (game->s_map->map[y][x] != '1')
		&& (game->s_map->map[y][x] != '0'))
	{
		error_message("non-valid character");
		free_game_map(game);
	}
}
