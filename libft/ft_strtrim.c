/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:24:33 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/20 14:26:14 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	char	*p;
	size_t	i;
	size_t	last_index;

	i = 0;
	if (!set || !s1)
	{
		return (ft_strdup(""));
	}
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	last_index = ft_strlens(s1) - 1;
	while (ft_strchr(set, s1[last_index]) && last_index)
		last_index--;
	p = ft_substr(s1, i, last_index - i + 1);
	return (p);
}
