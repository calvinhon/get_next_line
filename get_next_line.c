/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:24:56 by chon              #+#    #+#             */
/*   Updated: 2024/08/15 13:25:35 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_excess_buffer(char *buffer)
{
	int		len_incl_nl;
	int		len_excl_nl;
	char	*new_buffer;

	if (!ft_strchr(buffer, '\n'))
		return (NULL);
	len_incl_nl = ft_strchr(buffer, '\n') - buffer + 1;
	len_excl_nl = ft_strlen(buffer) - len_incl_nl;
	if (!len_excl_nl)
		return (free(buffer), NULL);
	new_buffer = malloc(len_excl_nl + 1);
	if (!new_buffer)
		return (NULL);
	ft_memcpy(new_buffer, buffer + len_incl_nl, len_excl_nl);
	new_buffer[len_excl_nl] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		len_incl_nl;

	if (!ft_strchr(buffer, '\n'))
		return (buffer);
	len_incl_nl = ft_strchr(buffer, '\n') - buffer + 1;
	line = malloc(len_incl_nl + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, len_incl_nl);
	line[len_incl_nl] = '\0';
	return (line);
}

char	*pull_text(char *buffer, int fd)
{
	char	*text;
	int		bytes_read;

	text = malloc((long long)BUFFER_SIZE + 1);
	if (!text)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, text, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(text), NULL);
		text[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, text);
	}
	free(text);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX - 1)
		return (NULL);
	buffer[fd] = pull_text(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);	
	line = get_line(buffer[fd]);
	buffer[fd] = get_excess_buffer(buffer[fd]);
	return (line);
}
