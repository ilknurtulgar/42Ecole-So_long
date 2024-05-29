/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:15:01 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 13:15:59 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_control(char *path)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd <= 0)
	{
		error_message("wrong file path");
		close(fd);
		exit(1);
	}
	close(fd);
}

void	extent_control(char *path)
{
	int	len;

	len = ft_strlens(path);
	if (path[len - 5] == '/')
	{
		error_message("hidden file extension");
		exit(1);
	}
	if (path[len - 1] != 'r' || path[len - 2] != 'e' || path[len - 3] != 'b'
		|| path[len - 4] != '.')
	{
		error_message("wrong file extension");
		exit(1);
	}
}
