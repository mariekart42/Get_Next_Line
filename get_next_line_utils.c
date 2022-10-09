#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t x;

	x = 0;
	while(str[x] != "\0")
		x++;
	return(x);
}

char	*strchr(char *str, char c)
{
	int i;
	
	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == c)
			return(&str[i]);
		i++;
	}
	return(NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int i;
	int x;
	char *buffer;
	
	i = 0;
	x = 0;
	if(!str1 || !str2)
		return(NULL);
	buffer = (char*)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if(!buffer)
		return(NULL);
	while(str1[i] != "\0")
		buffer[i] = str1[i];
		i++;
	y = 0;
	while(str2[x] != "\0")
		buffer[x + i] = str2[x];
		x++;
	buffer[i + x] == "\0";
	return(buffer); 
}

char	*get_read_line(char *buffer) //return the line being read
{
	int	i;
	char *line;
	
	i = 0;
	if(!buffer[i])
		return(NULL);
	while(buffer[i] != "\0" && buffer[i] != "\n") // search for the \0 or \n
		i++;
	line = malloc(sizeof(char) * (i + 2)); //allocate enough memory in my new string
	if(!line)
		return(NULL);
	i = 0;
	while(buffer[i] != "\0" && buffer[i] != "\n") // copy character by character from my source to new string
		line[i] = buffer[i];
		i++;
	if(buffer[i] == "\n") // in case we copied until \n, we have to add it to the new string too
		line[i++] = "\n";
	line[i] = "\0";
	return(line);
}

