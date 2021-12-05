/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:52:04 by ynakashi          #+#    #+#             */
/*   Updated: 2021/09/26 12:52:05 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

size_t	gnl_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*str++ != '\0')
		length++;
	return (length);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (gnl_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (gnl_strlen(src));
}

char	*gnl_strndup(const char *s1, size_t n)
{
	char	*ptr;

	ptr = (char *)malloc(n + sizeof(char));
	if (!ptr)
		return (NULL);
	else
		gnl_strlcpy(ptr, s1, n + 1);
	return (ptr);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	gnl_strlcpy(dst, s1, s1_len + 1);
	gnl_strlcpy(dst + s1_len, s2, s2_len + 1);
	return (dst);
}
