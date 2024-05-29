/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:08:09 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 15:18:00 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_rc(t_game *game, char *path)
{
	int		i;
	int		tlenght;
	char	*temp;

	i = 0;
	game->fd = open(path, O_RDWR);
	if (game->fd < 0)
		error_fd();
	temp = get_next_line(game->fd);
	is_map(temp);
	tlenght = ft_strlen(temp);
	if (temp[tlenght - 1] == '\n')
		game->s_map->col = (tlenght - 1);
	else
		game->s_map->col = tlenght;
	while (temp != NULL)
	{
		free(temp);
		temp = get_next_line(game->fd);
		i++;
	}
	close(game->fd);
	return (i);
}

void	map_malloc(t_game *game, char *path)
{
	game->s_map->rows = count_rc(game, path);
	game->temp_map = (char **)malloc(sizeof(char *) * (game->s_map->rows + 1));
	game->s_map->map = (char **)malloc(sizeof(char *) * (game->s_map->rows
				+ 1));
	if (!game->s_map->map || !game->temp_map)
	{
		if (game->s_map->map)
			malloc_free(game, game->s_map->map);
		if (game->temp_map)
			malloc_free(game, game->temp_map);
		error_message("failed to allocate space in memory");
		exit(1);
	}
}

void	main_map(t_game *game, char *path)
{
	char	*minstr;
	int		i;

	minstr = NULL;
	i = 0;
	game->fd = open(path, O_RDWR);
	if (game->fd < 0)
		error_fd();
	while (i < game->s_map->rows)
	{
		minstr = get_next_line(game->fd);
		game->s_map->map[i] = ft_strtrim(minstr, "\n");
		free(minstr);
		i++;
	}
	game->s_map->map[game->s_map->rows] = NULL;
	close(game->fd);
}

void	copy_map(t_game *game, char *path)
{
	int		i;
	char	*mintstr;

	mintstr = NULL;
	game->fd = open(path, O_RDWR);
	if (game->fd < 0)
		error_fd();
	i = 0;
	while (i < game->s_map->rows)
	{
		mintstr = get_next_line(game->fd);
		game->temp_map[i] = ft_strtrim(mintstr, "\n");
		free(mintstr);
		i++;
	}
	game->temp_map[game->s_map->rows] = NULL;
	close(game->fd);
}

void	read_map(t_game *game, char *path)
{
	map_malloc(game, path);
	main_map(game, path);
	copy_map(game, path);
}
