/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:18:01 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 15:48:45 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_game(t_game *game)
{
	game->mlx = mlx_init();
	get_image(game);
	game->window = mlx_new_window(game->mlx, game->s_map->col * 64,
			game->s_map->rows * 64, "so_long");
	set_image(game);
	mlx_key_hook(game->window, key_press, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}

void	check_map(t_game *game)
{
	map_size_cont(game);
	line_valid(game);
	map_valid(game);
	character_count_check(game);
	is_game_played(game);
}

void	first_control(char *path)
{
	xpm_control_1();
	xpm_control_2();
	file_control(path);
	extent_control(path);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error_message("you gave wrong number of arguments");
	game = ft_calloc(1, sizeof(t_game));
	game->s_map = ft_calloc(1, sizeof(t_map));
	if (!game || !game->s_map)
	{
		error_message("failed to allocate space in memory");
		if (game)
			free(game);
		if (game->s_map)
			free(game->s_map);
		exit(1);
	}
	first_control(argv[1]);
	read_map(game, argv[1]);
	check_map(game);
	mlx_game(game);
}
