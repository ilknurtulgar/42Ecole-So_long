/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:14:53 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 13:30:06 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size_cont(t_game *game)
{
	if (game->s_map->rows > 22 || game->s_map->col > 55)
	{
		error_message("map size is too big");
		free_game_map(game);
	}
}

void	line_valid(t_game *game)
{
	int	i;
	int	len;

	i = -1;
	while (++i < game->s_map->rows)
	{
		len = ft_strlens(game->s_map->map[i]);
		if (len != game->s_map->col)
		{
			error_message("line size error");
			free_game_map(game);
		}
	}
}

void	map_corner_close_y(t_game *game, int y)
{
	if ((game->s_map->map[y][0] != '1') || (game->s_map->map[y][game->s_map->col
			- 1] != '1'))
	{
		error_message("non-valid y map corner");
		free_game_map(game);
	}
}

void	map_corner_close_x(t_game *game, int x)
{
	if ((game->s_map->map[0][x] != '1') || (game->s_map->map[game->s_map->rows
			- 1][x] != '1'))
	{
		error_message("non-valid x map corner");
		free_game_map(game);
	}
}

void	map_valid(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->s_map->rows)
	{
		x = 0;
		while (x < game->s_map->col)
		{
			character_valid(game, x, y);
			map_corner_close_x(game, x);
			if (game->s_map->map[y][x] == 'E')
			{
				game->exit_count++;
				e_map_valid(game, x, y);
			}
			else if (game->s_map->map[y][x] == 'P')
				p_map_valid(game, x, y);
			else if (game->s_map->map[y][x] == 'C')
				game->count_collectable++;
			x++;
		}
		map_corner_close_y(game, y);
		y++;
	}
}
