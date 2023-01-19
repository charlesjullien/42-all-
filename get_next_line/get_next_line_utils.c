/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:08:45 by cjullien          #+#    #+#             */
/*   Updated: 2021/01/07 16:53:43 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < len)
		len = (unsigned int)ft_strlen(s);
	i = 0;
	new = (char*)malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	if (start > (unsigned int)ft_strlen((char *)s))
	{
		new[i] = '\0';
		return (new);
	}
	while (i < len && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(const char *source)
{
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((char*)source);
	new = (char*)malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	while (source[i])
	{
		new[i] = source[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *str, int to_find)
{
	int	i;

	i = 0;
	while (str[i] != to_find)
	{
		if (str[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)&str[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	i = 0;
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
