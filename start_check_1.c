/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:42:22 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 13:15:34 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_xpm_1(int fd_coin, int fd_empty, int fd_wall)
{
	close(fd_coin);
	close(fd_empty);
	close(fd_wall);
}

void	close_xpm_2(int fd_player, int fd_none_exit, int fd_exit)
{
	close(fd_exit);
	close(fd_player);
	close(fd_none_exit);
}

void	xpm_control_1(void)
{
	int	fd_coin;
	int	fd_empty;
	int	fd_wall;

	fd_coin = open("./textures/coin.xpm", O_RDWR);
	fd_empty = open("./textures/empty.xpm", O_RDWR);
	fd_wall = open("./textures/wall.xpm", O_RDWR);
	if (fd_coin <= 0 && fd_empty <= 0 && fd_wall <= 0)
	{
		error_message("wrong xpm file");
		close_xpm_1(fd_coin, fd_empty, fd_wall);
		exit(1);
	}
	close_xpm_1(fd_coin, fd_empty, fd_wall);
}

void	xpm_control_2(void)
{
	int	fd_exit;
	int	fd_player;
	int	fd_none_exit;

	fd_none_exit = open("./textures/none_exit.xpm", O_RDWR);
	fd_exit = open("./textures/exit.xpm", O_RDWR);
	fd_player = open("./textures/player.xpm", O_RDWR);
	if (fd_exit <= 0 && fd_player <= 0 && fd_none_exit <= 0)
	{
		error_message("wrong xpm file");
		close_xpm_2(fd_player, fd_none_exit, fd_exit);
		exit(1);
	}
	close_xpm_2(fd_player, fd_none_exit, fd_exit);
}
