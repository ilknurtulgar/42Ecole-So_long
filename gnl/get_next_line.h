/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:51:45 by itulgar           #+#    #+#             */
/*   Updated: 2024/03/26 15:39:17 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);
int		ft_nl(char *s);
char	*ft_strjoin(char *str, char *temp);
char	*ft_new_line(char *str);
size_t	ft_strlen(char *s);
char	*ft_cutline(char *str);

#endif
