/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesboui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:57:33 by ldesboui          #+#    #+#             */
/*   Updated: 2025/11/12 14:33:49 by ldesboui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		++i;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*ptr;

	i = 0;
	size = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}

ssize_t	ft_strchr(const char *s, int c, int size_read)
{
	size_t	i;

	if (!s)
		return (-1);
	if (size_read == 0 && ft_strlen(s))
		return (ft_strlen(s) - 1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		++i;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*copy;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s1)
	{
		copy = ft_strdup(s2);
		return (copy);
	}
	copy = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		++i;
	}
	while (s2[k])
		copy[i++] = s2[k++];
	copy[i] = '\0';
	boosted_free(&s1);
	return (copy);
}

char	*ft_substr(char	*s, char *tofree, unsigned int start, size_t len)
{
	char		*ret;
	size_t		i;

	i = 0;
	if (!s || !tofree)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		ret = (char *)malloc(1);
		return (ret);
	}
	if (len > ft_strlen(s) - start)
		len = (ft_strlen(s) - start);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		++i;
	}
	ret[i] = '\0';
	free(tofree);
	return (ret);
}
