/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:18:52 by gamoraes          #+#    #+#             */
/*   Updated: 2024/02/05 02:37:55 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static char	*extract_line(char *line)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	len = ft_strlen(line) - i;
	tmp = ft_substr(line, i + 1, len);
	if (*tmp == '\0')
	{
		free(tmp);
		tmp = NULL;
	}
	line[i + 1] = '\0';
	return (tmp);
}

static char	*find_char(const char *s, char target)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (tmp[i])
	{
		if (tmp[i] == target)
			return (tmp);
		i++;
	}
	return (NULL);
}

static char	*read_line(int fd, char *buffer, char *storage)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (!storage)
			storage = ft_strdup("");
		tmp = storage;
		storage = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (find_char(buffer, '\n'))
			break ;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, storage);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	storage = extract_line(line);
	return (line);
}
