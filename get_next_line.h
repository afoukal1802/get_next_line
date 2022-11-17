#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

ssize_t	ft_strlen(char	*s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
char	*ft_readed(char **handle, int fd);
char	*ft_get_line(char *handle);
char	*ft_after_line(char **handle);
char	*get_next_line(int fd);



#endif
