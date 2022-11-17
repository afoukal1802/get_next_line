/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafoukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:29:40 by mafoukal          #+#    #+#             */
/*   Updated: 2022/11/17 18:41:47 by mafoukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_readed(char **handle, int fd)
{
	char	*buffer;
	ssize_t	rd;

	buffer = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(*handle), *handle = NULL, NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == 0)
			return (free(buffer), *handle);
		if (rd == -1)
			return (free(buffer), free(*handle), *handle = NULL, NULL);
		buffer[rd] = '\0';
		*handle = ft_strjoin(*handle, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), *handle);
}

void	ft_no_newline(char	**handle, char **line, ssize_t len)
{
	ssize_t	i;

	i = 0;
	*line = (char *) ft_calloc(len + 1, sizeof(char));
	if (!(*line))
	{
		free(*handle);
		return ;
	}
	while (i < len)
	{
		(*line)[i] = (*handle)[i];
		i++;
	}
}

char	*ft_get_line(char **handle)
{
	ssize_t	i;
	char	*line;

	i = 0;
	line = NULL;
	while ((*handle)[i] && (*handle)[i] != '\n')
		i++;
	if (ft_strchr(*handle, '\n'))
	{
		line = (char *) ft_calloc(i + 2, sizeof(char));
		if (!line)
			return (free(*handle), *handle = NULL, NULL);
		i = 0;
		while ((*handle)[i] && (*handle)[i] != '\n')
		{
			line[i] = (*handle)[i];
			i++;
		}
		line[i] = '\n';
	}
	else
		ft_no_newline(handle, &line, i);
	return (line);
}

char	*ft_after_line(char **handle)
{
	ssize_t	i;
	ssize_t	y;
	char	*after;

	i = 0;
	while ((*handle)[i] && (*handle)[i] != '\n')
		i++;
	if (ft_strchr(*handle, '\n'))
	{
		after = (char *) ft_calloc(ft_strlen(*handle) - i, sizeof(char));
		if (!after)
			return (free(*handle), *handle = NULL, NULL);
		y = 0;
		i++;
		while ((*handle)[i])
			after[y++] = (*handle)[i++];
		return (free(*handle), *handle = NULL, after);
	}
	else
		return (free(*handle), *handle = NULL, NULL);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*handle[OPEN_MAX];
	char		*line;

	if (read(fd, NULL, 0) == -1 && handle[fd])
		return (free(handle[fd]), handle[fd] = NULL, NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	handle[fd] = ft_readed(&(handle[fd]), fd);
	if (!handle[fd])
		return (NULL);
	if (*(handle[fd]) == '\0')
		return (free(handle[fd]), handle[fd] = NULL, NULL);
	line = ft_get_line(&(handle[fd]));
	if (!line)
		return (free(handle[fd]), handle[fd] = NULL, NULL);
	handle[fd] = ft_after_line(&(handle[fd]));
	return (line);
}
