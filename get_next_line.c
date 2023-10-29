/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrba <mstrba@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:50:27 by mstrba            #+#    #+#             */
/*   Updated: 2023/10/29 14:06:46 by mstrba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char	*res)
{
	
}

char	*ft_read_file(int fd, char	*res)
{
	char	*buffer;
	char	*temp;
	size_t	bytes_read;

	bytes_read = 1;
	if (!res)
		res = calloc(1, sizeof(char));
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!res || !buffer)
		return (NULL);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(res, buffer);
		free(res);
		res = temp;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer || !ft_strchr(buffer, '\n'))
		buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_read_line();
	return (line);
}
