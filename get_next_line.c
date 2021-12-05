/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:34:26 by ynakashi          #+#    #+#             */
/*   Updated: 2021/09/15 13:20:43 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*iterate(char **holder, ssize_t *flag, char **buf, int fd)
{
	char	*tmp;
	char	*newline;

	while (1)
	{
		newline = gnl_strchr(*holder, '\n');
		if (newline)
			return (newline);
		*flag = read(fd, *buf, BUFFER_SIZE);
		if (*flag == 0 || *flag == -1)
			return (NULL);
		(*buf)[*flag] = '\0';
		tmp = gnl_strjoin(*holder, *buf);
		if (!tmp)
		{
			*flag = ERROR;
			return (NULL);
		}
		free(*holder);
		*holder = tmp;
	}
}

void	exist_newline(char **ret, char **newline, char **holder, ssize_t *flag)
{
	char	*tmp;

	*ret = gnl_strndup(*holder,*newline - *holder + 1);
	if (!*ret)
	{
		*flag = ERROR;
		return ;
	}
	tmp = gnl_strndup(*newline + 1, gnl_strlen(*newline + 1));
	free(*holder);
	*holder = tmp;
	if (!*holder)
	{
		*flag = ERROR;
		free(*ret);
		*ret = NULL;
	}
}

void	end_of_file(char **holder, char **ret, ssize_t *flag)
{
	if (**holder)
	{
		*ret = gnl_strndup(*holder, gnl_strlen(*holder));
		free(*holder);
		*holder = NULL;
	}
	else
		*flag = ERROR;
}

void	failure(char **holder, char **ret)
{
	free(*holder);
	*holder = NULL;
	*ret = NULL;
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*holder[OPEN_MAX];
	ssize_t		flag;
	char		*newline;
	char		*buf;

	if (fd < 0 || fd > OPEN_MAX - 1
		|| BUFFER_SIZE < 1 || BUFFER_SIZE >= SIZE_MAX)
		return (NULL);
	if (!holder[fd])
		holder[fd] = gnl_strndup("", 0);
	if (!holder[fd])
		return (NULL);
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	newline = iterate(&holder[fd], &flag, &buf, fd);
	free(buf);
	if (newline)
		exist_newline(&ret, &newline, &holder[fd], &flag);
	else
		end_of_file(&holder[fd], &ret, &flag);
	if (flag == ERROR)
		failure(&holder[fd], &ret);
	return (ret);
}
