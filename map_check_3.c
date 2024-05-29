/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:37:57 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 15:20:20 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_recursive(char **map, int x, int y)
{
	map[y][x] = '*';
	if (map[y + 1][x] != '1' && map[y + 1][x] != '*')
		path_recursive(map, x, y + 1);
	if (map[y - 1][x] != '1' && map[y - 1][x] != '*')
		path_recursive(map, x, y - 1);
	if (map[y][x + 1] != '1' && map[y][x + 1] != '*')
		path_recursive(map, x + 1, y);
	if (map[y][x - 1] != '1' && map[y][x - 1] != '*')
		path_recursive(map, x - 1, y);
}

void	is_game_played(t_game *game)
{
	int	x;
	int	y;

	path_recursive(game->temp_map, game->s_map->p_x, game->s_map->p_y);
	y = -1;
	while (++y < game->s_map->rows)
	{
		x = -1;
		while (++x < game->s_map->col)
		{
			if (game->temp_map[y][x] != '*' && game->temp_map[y][x] != '1'
				&& game->temp_map[y][x] != '0')
			{
				error_message("unplayable map");
				free_game_map(game);
				exit(1);
			}
		}
	}
}
