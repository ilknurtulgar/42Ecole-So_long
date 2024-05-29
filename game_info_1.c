/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:32:58 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 15:27:08 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *str)
{
	ft_printf("Error: << %s honey <3 >>\n", str);
}

void	close_map(t_game *game)
{
	free_map(game, game->temp_map);
	free_map(game, game->s_map->map);
	free(game->s_map);
}

void	free_game_map(t_game *game)
{
	close_map(game);
	free(game);
	exit(1);
}

void	free_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->empty);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_window(game->mlx, game->window);
}

int	close_window(t_game *game)
{
	free_image(game);
	close_map(game);
	free(game);
	ft_printf("<< close window honey>> \n");
	exit(0);
}
