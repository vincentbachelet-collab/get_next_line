/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:31:33 by vbachele          #+#    #+#             */
/*   Updated: 2021/05/26 17:04:24 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnljoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*d;

	if (!s1 || !s2)
		return (0);
	d = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!d)
		return (0);
	i = 0;
	while (s1[i] && s1)
	{
		d[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		d[i + j] = s2[j];
		j++;
	}
	d[i + j] = 0;
	if (s1)
		free((char *)s1);
	return (d);
}

char	*ft_gnldup(const char *s1, const char *srcfree)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = malloc((sizeof(char) * (ft_strlen(s1) + 1)));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i] && s1)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	if (srcfree)
		free((char *)srcfree);
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dictionnaire;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		dictionnaire = malloc(sizeof(char) * ft_strlen(s) + 1);
	else
		dictionnaire = malloc(sizeof(char) * (len + 1));
	if (!dictionnaire)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			dictionnaire[i] = s[start + i];
			i++;
		}
		dictionnaire[i] = '\0';
	}
	else
		dictionnaire[0] = '\0';
	return (dictionnaire);
}