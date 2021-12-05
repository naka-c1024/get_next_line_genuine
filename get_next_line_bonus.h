/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:50:52 by ynakashi          #+#    #+#             */
/*   Updated: 2021/09/26 12:51:19 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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