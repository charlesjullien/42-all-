/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:18:55 by mabuchar          #+#    #+#             */
/*   Updated: 2022/01/26 16:57:18 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strlen_const(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	if (!src || !dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = ft_strlen_const(s);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		ft_exit(NULL, "Warning : Malloc failed\n");
	ft_memcpy(str, s, i);
	str[i] = '\0';
	return (str);
}

char	*ft_substr_gnl(char const *s, int start, int len)
{
	char	*str;
	int		i;
	int		end;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !str)
		return (NULL);
	if (start > ft_strlen_const(s))
	{
		str[0] = '\0';
		return (str);
	}
	end = start + len;
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	i = ft_strlen_const(s1);
	j = ft_strlen_const(s2);
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		ft_exit(NULL, "Warning : Malloc failed\n");
	ft_memcpy(str, s1, i);
	free(s1);
	ft_memcpy(str + i, s2, j);
	str[i + j] = '\0';
	return (str);
}
