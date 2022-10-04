#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*get_line(char *buffer, int fd);
char	*get_read_line(char *buffer);
char	ft_get_rest(char *buffer);
char	strchr(char *str, char c);
char	ft_strjoin(char *str1, char *str2);


#endif