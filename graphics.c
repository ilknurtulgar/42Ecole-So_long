/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:56:59 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 13:22:13 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_image(t_game *game)
{
	int	x;
	int	y;

	game->coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", &x, &y);
	game->empty = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm", &x,
			&y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &x,
			&y);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &x, &y);
	game->none_exit = mlx_xpm_file_to_image(game->mlx, "textures/none_exit.xpm",
			&x, &y);
	if (game->wall == NULL || game->coin == NULL || game->empty == NULL
		|| game->exit == NULL || game->player == NULL
		|| game->none_exit == NULL)
		error_message("missing image file");
}

void	put_check_image(t_game *game, int x, int y)
{
	if (game->s_map->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, x * 64, y
			* 64);
	else if (game->s_map->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->empty, x * 64, y
			* 64);
	else if (game->s_map->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->coin, x * 64, y
			* 64);
	else if (game->s_map->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player, x * 64, y
			* 64);
	else if (game->s_map->map[y][x] == 'E')
	{
		if (game->s_map->map[game->s_map->p_y][game->s_map->p_x]
				== game->s_map->map[game->s_map->e_y][game->s_map->e_x])
			mlx_put_image_to_window(game->mlx, game->window, game->none_exit, x
				* 64, y * 64);
		else
			mlx_put_image_to_window(game->mlx, game->window, game->exit, x * 64,
				y * 64);
	}
}

void	set_image(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->s_map->rows)
	{
		x = 0;
		while (game->s_map->map[y][x])
		{
			put_check_image(game, x, y);
			x++;
		}
		y++;
	}
}
