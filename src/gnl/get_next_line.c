#include "../../so_long.h"

static char	*fill_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	be_read;
	char	*swp;

	be_read = 1;
	while (be_read > 0)
	{
		be_read = read(fd, buffer, BUFFER_SIZE);
		if (be_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		if (be_read == 0)
			break ;
		buffer[be_read] = '\0';
		if (!left_c)
			left_c = ft_strdup("");
		swp = left_c;
		left_c = ft_strjoin(swp, buffer);
		free(swp);
		swp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
static char	*cut_line(char *line_buffer)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == '\n')
		line_buffer[i] = '\0';
	if (line_buffer[i + 1])
		left_c = ft_strdup(line_buffer + i + 1);
	else
		left_c = NULL;
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	left_c = fill_buffer(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!left_c)
		return (NULL);
	line = ft_strdup(left_c);
	left_c = cut_line(left_c);
	return (line);
}
