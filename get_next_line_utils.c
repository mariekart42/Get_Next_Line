#include "get_next_line.h"

/**
 * @brief	function erases the data in the n bytes of the memory
       		starting at the location pointed to by s, by writing zeros 
			(bytes containing '\0') to that area.
 * @param str space in memory that gets sized to null
 * @param n lengh we want to str gets nulled
 */
void	ft_bzero(void *str, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *) str;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/**
 * @brief	function allocates 'nitems' bytes of memory, each in size of 'size' 
 			(int, char etc)
			different to malloc, sets all places to '\0'
 * 
 * @param count 
 * @param size 
 * @return void* returns pointer to allocated memory
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*output;

	if (count >= 4294967295 || size >= 4294967295)
		return (NULL);
	output = malloc(count * size);
	if (!output)
		return (NULL);
	ft_bzero(output, count * size);
	return (output);
}

size_t	ft_strlen(char *str)
{
	size_t x;

	x = 0;
	while(str[x] != '\0')
		x++;
	return(x);
}

// char	*ft_strchr(char *str, char c)
// {
// 	int i;
	
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == c)
// 			return(&str[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str[0] == (char) c)
		return ((char *) str);
	while (str[i] != '\0')
	{
		if ((c == '\0') && (str[i + 1] == '\0'))
			return ((char *) str + i + 1);
		if (str[i] == (char)c)
		{
			return ((char *) str + i);
		}
		i++;
	}
	return ((char *) '\0');
}

// char	*ft_strjoin(char *str1, char *str2)
// {
// 	int i;
// 	int x;
// 	char *buffer;
// 	int y;
	
// 	i = 0;
// 	x = 0;
// 	if(!str1 || !str2)
// 		return(NULL);
// 	buffer = (char*)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
// 	if(!buffer)
// 		return(NULL);
// 	while(str1[i] != '\0')
// 	{
// 		buffer[i] = str1[i];
// 		i++;
// 	}
// 	y = 0;
// 	while(str2[x] != '\0')
// 		buffer[x + i] = str2[x];
// 		x++;
// 	buffer[i + x] = '\0';
// 	return(buffer); 
// }
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *) malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!ptr)
		return (NULL);
	k = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		ptr[i] = s2[k];
		i++;
		k++;
	}
	ptr[i] = '\0';
	free((void*)s1);
	return (ptr);
}

// char	*get_read_line(char *buffer) //return the line being read
// {
// 	int	i;
// 	char *line;
	
// 	i = 0;
// 	if(!buffer[i])
// 		return(NULL);
// 	while(buffer[i] != '\0' && buffer[i] != '\n') // search for the \0 or \n
// 		i++;
// 	line = malloc(sizeof(char) * (i + 2)); //allocate enough memory in my new string
// 	if(!line)
// 		return(NULL);
// 	i = 0;
// 	while(buffer[i] != '\0' && buffer[i] != '\n') // copy character by character from my source to new string
// 		line[i] = buffer[i];
// 		i++;
// 	if(buffer[i] == '\n') // in case we copied until \n, we have to add it to the new string too
// 		line[i++] = '\n';
// 	line[i] = '\0';
// 	return(line);
// }

