/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:46:46 by itulgar           #+#    #+#             */
/*   Updated: 2024/05/09 19:05:15 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			substring_lenght;
	unsigned int	start_l;
	char			*substring;

	if (len == 0 || !s || start >= (unsigned int)ft_strlens(s))
		return (ft_strdup(""));
	substring_lenght = 0;
	start_l = start;
	while (s[start_l++] && substring_lenght < len)
		substring_lenght++;
	substring = malloc(sizeof(char) * (substring_lenght + 1));
	if (!substring)
		return (NULL);
	substring_lenght = 0;
	while (s[start] && len-- > 0)
		substring[substring_lenght++] = s[start++];
	substring[substring_lenght] = '\0';
	return (substring);
}
