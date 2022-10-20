#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
#endif

# include <stdlib.h>
# include <unistd.h>
# include<stdio.h>

#include <stddef.h>
#include <string.h>
#include <strings.h>

// libs you need for using open()
# include <fcntl.h> 
# include <errno.h> 
#include <sys/stat.h>

// libs you need for using read()
# include <sys/types.h>
# include <sys/uio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*get_line(char **buffer, int fd);
char	*get_read_line(char *buffer);
char	*ft_get_rest(char *buffer);
// char	*ft_strchr(char *str, char c); // your function
char	*ft_strchr(const char *str, int c); // maries better function
char	*ft_strjoin(char const *s1, char const *s2);
char	*create_last(char *buff, char *line);
void	buff_after_line(char *buff);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *str, size_t n);
#endif
