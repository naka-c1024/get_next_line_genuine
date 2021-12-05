/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:28:19 by ynakashi          #+#    #+#             */
/*   Updated: 2021/09/14 15:55:08 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define ERROR -1

char	*get_next_line(int fd);

char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *str);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
char	*gnl_strndup(const char *s1, size_t n);
char	*gnl_strjoin(char const *s1, char const *s2);

#endif