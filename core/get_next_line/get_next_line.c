/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muali <muali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 03:22:48 by muali             #+#    #+#             */
/*   Updated: 2026/07/13 21:36:07 by muali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

char	*read_from_file(int fd, char *remainder)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(remainder));
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (ft_free(remainder));
		}
		buffer[bytes_read] = '\0';
		if (bytes_read != 0)
			remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
			break ;
	}
	free(buffer);
	return (remainder);
}

char	*extract_line(char *remainder)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	line = malloc((i + 1 + (remainder[i] == '\n')) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_remainder(char *remainder)
{
	char	*new_remainder;
	size_t	i;
	size_t	j;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i] || !remainder[i + 1])
		return (ft_free(remainder));
	new_remainder = malloc((ft_strlen(remainder) - i + 1) * sizeof(char));
	if (!new_remainder)
		return (ft_free(remainder));
	i++;
	j = 0;
	while (remainder[i])
	{
		new_remainder[j] = remainder[i];
		i++;
		j++;
	}
	new_remainder[j] = '\0';
	free(remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (remainder)
			remainder = ft_free(remainder);
		return (NULL);
	}
	remainder = read_from_file(fd, remainder);
	if (!remainder)
		return (NULL);
	line = extract_line(remainder);
	if (!line)
	{
		remainder = ft_free(remainder);
		return (NULL);
	}
	remainder = update_remainder(remainder);
	return (line);
}
