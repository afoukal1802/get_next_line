#include "get_next_line.h"

ssize_t	ft_strlen(char	*s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *) malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
		ptr[i++] = 0;
	return (ptr);
}

char	*ft_strdup(char *s)
{
	ssize_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	ptr = (char *) ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nw;
	ssize_t	i;
	ssize_t	y;

	if (!s1)
		return (ft_strdup(s2));
	nw = (char *) ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!nw)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		nw[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2[y])
		nw[i++] = s2[y++];
	free(s1);
	nw[i] = 0;
	return (nw);
}

char	*ft_strchr(char *s, char c)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}
