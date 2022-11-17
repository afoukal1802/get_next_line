#include "get_next_line.h"

char	*ft_readed(char **handle, int fd)
{
	char	*buffer;
	ssize_t	rd;

	buffer = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == 0)
			return (free(buffer), *handle);
		if (rd == -1)
			return (free(buffer), free(*handle), *handle = NULL, NULL);
		*handle = ft_strjoin(*handle, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (free(buffer), *handle);
}

char	*ft_get_line(char *handle)
{
	ssize_t	i;
	char	*line;

	i = 0;
	line = NULL;
	while (handle[i] && handle[i] != '\n')
		i++;
	if (ft_strchr(handle, '\n'))
	{
		line = (char *) ft_calloc(i + 2, sizeof(char));
		if (!line)
			return (NULL);
		i = 0;
		while (handle[i] && handle[i] != '\n')
		{
			line[i] = handle[i];
			i++;
		}
		line[i] = '\n';
	}
	else
	{
		line = (char *) ft_calloc(i + 1, sizeof(char));
		i = 0;
		if (!line)
			return (NULL);
		while (handle[i])
		{
			line[i] = handle[i];
			i++;
		}
	}
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
			return (NULL);
		y = 0;
		i++;
		while ((*handle)[i])
			after[y++] = (*handle)[i++];
		return (free(*handle), after);
	}
	else
		return (free(*handle), *handle = NULL,  NULL);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*handle;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	handle = ft_readed(&handle, fd);
	if (!handle)
		return (NULL);
	line = ft_get_line(handle);
	if (!line)
		return (NULL);
	handle = ft_after_line(&handle);
	return (line);
}
