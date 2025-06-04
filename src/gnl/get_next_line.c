/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouali <ebouali@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:54:24 by ebouali           #+#    #+#             */
/*   Updated: 2025/06/01 17:54:29 by ebouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"


char	*ft_strchr(const char *s, int c)
{
	int i;

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



static char	*cut_line(char *line_buffer)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == '\0' || line_buffer[1] == '\0')
		return (NULL);
	left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = '\0';
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
	line = fill_buffer(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_c = cut_line(line);
	return (line);
}
/*static char	**get_left_c_addr(void)
{
    static char	*left_c = NULL;
    return (&left_c);
}

void	free_gnl_static(void)
{
    char **left_c_ptr = get_left_c_addr();
    if (*left_c_ptr)
    {
        free(*left_c_ptr);
        *left_c_ptr = NULL;
    }
}*/


/*
char	*ft_strchr(const char *s, int c)
{
    int i;

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

static char	**get_left_c_addr(void)
{
    static char	*left_c = NULL;
    return (&left_c);
}

static char	*fill_buffer(int fd, char *left_c)
{
    char	*buffer;
    char	*tmp;
    ssize_t	be_read;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    be_read = 1;
    while (be_read > 0 && !ft_strchr(left_c, '\n'))
    {
        be_read = read(fd, buffer, BUFFER_SIZE);
        if (be_read == -1)
        {
            free(buffer);
            free(left_c);
            return (NULL);
        }
        buffer[be_read] = '\0';
        tmp = left_c;
        left_c = ft_strjoin(tmp ? tmp : "", buffer);
        free(tmp);
    }
    free(buffer);
    return (left_c);
}

static char	*extract_line(char *left_c)
{
    size_t	i = 0;
    char	*line;

    if (!left_c || !left_c[0])
        return (NULL);
    while (left_c[i] && left_c[i] != '\n')
        i++;
    line = ft_substr(left_c, 0, left_c[i] == '\n' ? i + 1 : i);
    return (line);
}

static char	*update_left_c(char *left_c)
{
    size_t	i = 0;
    char	*new_left;

    while (left_c[i] && left_c[i] != '\n')
        i++;
    if (!left_c[i])
    {
        free(left_c);
        return (NULL);
    }
    new_left = ft_substr(left_c, i + 1, ft_strlen(left_c) - i - 1);
    free(left_c);
    return (new_left);
}

char	*get_next_line(int fd)
{
    char	**left_c_ptr = get_left_c_addr();
    char	*line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    *left_c_ptr = fill_buffer(fd, *left_c_ptr);
    if (!*left_c_ptr)
        return (NULL);
    line = extract_line(*left_c_ptr);
    *left_c_ptr = update_left_c(*left_c_ptr);
    return (line);
}

void	free_gnl_static(void)
{
    char **left_c_ptr = get_left_c_addr();
    if (*left_c_ptr)
    {
        free(*left_c_ptr);
        *left_c_ptr = NULL;
    }
}
*/
	