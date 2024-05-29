/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:28:52 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 13:19:48 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game, char **map)
{
	int	j;

	j = 0;
	while (j < game->s_map->rows)
		free(map[j++]);
	if (map)
		free(map);
}

void	error_fd(void)
{
	error_message("fd small or equal from zero");
	exit(1);
}

void	is_map(char *temp)
{
	if (!temp || !temp[0])
	{
		error_message("map is empty");
		exit(1);
	}
}
