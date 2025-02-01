#include <stdlib.h>
#include <unistd.h>

static char	*free_and_return_null(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

static char	*extract_line(char **buffer)
{
	char	*line;
	char	*tmp;
	size_t	len;

	if (!*buffer || **buffer == '\0')
		return (free_and_return_null(buffer));
	len = 0;
	while ((*buffer)[len] && (*buffer)[len] != '\n')
		len++;
	if ((*buffer)[len] == '\n')
		line = ft_substr(*buffer, 0, len + 1);
	else
		line = ft_substr(*buffer, 0, len);
	if (!line)
		return (free_and_return_null(buffer));
	if ((*buffer)[len] == '\n')
		tmp = ft_strdup(*buffer + len + 1);
	else
		tmp = ft_strdup("");
	free(*buffer);
	*buffer = tmp;
	if (!*buffer)
		free_and_return_null(buffer);
	return (line);
}

static ssize_t	read_to_buffer(int fd, char **buffer)
{
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(*buffer, buf);
		free(*buffer);
		if (!tmp)
			return (-1);
		*buffer = tmp;
		if (ft_strchr(*buffer, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1040];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	if (!buffer[fd])
		return (NULL);
	bytes_read = read_to_buffer(fd, &buffer[fd]);
	if (bytes_read < 0 || (!bytes_read && (!buffer[fd] || *buffer[fd] == '\0')))
		return (free_and_return_null(&buffer[fd]));
	return (extract_line(&buffer[fd]));
}
