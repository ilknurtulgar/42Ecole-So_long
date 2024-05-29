/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:36:42 by itulgar           #+#    #+#             */
/*   Updated: 2024/04/04 19:00:46 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*dest;

	len = ft_strlens(src);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest != NULL)
	{
		i = 0;
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[len] = '\0';
	}
	return (dest);
}
