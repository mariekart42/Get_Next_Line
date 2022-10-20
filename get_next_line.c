
#include "get_next_line.h"

char	*get_read_line(char *buffer) //return the line being read
{
	int	i;
	char *line;
	
	i = 0;
	if(!buffer)
		return(NULL);
	while(buffer[i+1] != '\0' && buffer[i+1] != '\n') // search for the \0 or \n
		i++;
	i--; // buffer[i+1] because you otherwise enter heap memory that your not allowed to access
	line = ft_calloc(sizeof(char), (i + 2)); //allocate enough memory in my new string
	if (!line)
		return(NULL);
	i = 0;
	while(buffer[i] != '\0' && buffer[i] != '\n') // copy character by character from my source to new string
	{
		line[i] = buffer[i];
		i++;
	}
	if(buffer[i] == '\n') // in case we copied until \n, we have to add it to the new string too
		line[i++] = '\n';
	line[i] = '\0';

	return(line);
}

char	*ft_get_rest(char *buffer) //save all content that has not yet been read from fd
{ 
	int	x;
	int	y;
	char *new_buffer;


	
	x = 0;
	while(buffer[x] != '\0' && buffer[x] != '\n')
		x++;
	if(buffer[x] == '\0')
	{
		// free(buffer);
		return(0);
	}
	new_buffer = ft_calloc(sizeof(char), (ft_strlen(buffer) - x + 1));
	if (!new_buffer)
		return (NULL);
	x = x + 1;
	y = 0;
	while (buffer[x] != '\0')
		new_buffer[y++] = buffer[x++];
	new_buffer[y] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*create_last(char *buff, char *line)
{
	line = ft_strjoin(line, buff);
	buff[0] = '\0';
	return (line);
}

//locate the line that should be read in our fd
char	*get_line(char **buffer, int fd)
{
	char *temp;
	int byte_count;

	byte_count = 1; // setting it to 0 so we can actually enter the while loop
	
	temp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!temp)
	{
		return (NULL);
	}
	while(!ft_strchr(temp, '\n'))// && byte_count != 0) //while looking for a '\n'
	{   //check the bytes read, if no error has occured, save the amount of bytes read
		if (*temp) // we need to check if temp has content, *temp is the same as temp[0], so if there is no character at temp[0] we skip joining
			*buffer = ft_strjoin(*buffer, temp); // concatenate strings
		// concatenating before reading so previouse stuff can get joined as well
		byte_count = read(fd, temp, BUFFER_SIZE);
		if (byte_count <= 0 && (!**buffer))
		{
			free(*buffer);
			return (NULL);
		}
		if (!ft_strchr(temp, '\n') && byte_count < BUFFER_SIZE)
			return (create_last(temp, *buffer));
		if (byte_count == -1)
		{
			// free(byte_count); // you don't free integers lol
			return (NULL);
		}
		temp[byte_count] = '\0'; // add a null terminator at the last position stored in our temp
		
	}
	*buffer = ft_strjoin(*buffer, temp);
	free(temp);
	return(*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if(!buffer)
	{
		buffer = ft_calloc(sizeof(char), 1);
		buffer[0] = '\0';
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	get_line(&buffer, fd); // read our line for the \n character or any error
	if (!buffer)
	{
		return (NULL);
	}
	line = get_read_line(buffer); //return the line that was read
	buffer = ft_get_rest(buffer); // save all the content that has not yet been read from the fd
	if (line[0] == '\0')
	{
		free(line);
		free(buffer);
		return (NULL);
	}
	return (line); //return the line that was read
}

int main()
{

	int fd = open("test", O_RDONLY, 0);
	printf("check\n");
	printf("fd: %d\n", fd);
	
	char *str1 = get_next_line(fd);
	printf("first: %s\n", str1);
	free(str1);
	char *str2 = get_next_line(fd);
	printf("second: %s\n", str2);
	free(str2);
	char *str3 = get_next_line(fd);
	printf("third: %s\n", str3);
	free(str3);
	
}
