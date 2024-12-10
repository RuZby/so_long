/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeyel <tbeyel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:25:36 by tbeyel            #+#    #+#             */
/*   Updated: 2024/12/10 10:07:24 by tbeyel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_read_loop(char *line, char *buffer, ssize_t n_read, int fd)
{
	while (n_read > 0)
	{
		line = ft_strjoin_free(line, buffer);
		if (!line)
			return (NULL);
		ft_strlcpy(buffer, buffer + ft_strlen_char(buffer, '\n'),
			BUFFER_SIZE + 1);
		if (ft_strchr(line, '\n'))
			return (line);
		n_read = read(fd, buffer, BUFFER_SIZE);
		buffer[n_read] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		n_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (ft_strlen_char(buffer, '\0') != 0)
	{
		line = ft_strjoin_free(line, buffer);
		if (!line)
			return (NULL);
		ft_strlcpy(buffer, buffer + ft_strlen_char(buffer, '\n'),
			BUFFER_SIZE + 1);
		if (ft_strchr(line, '\n'))
			return (line);
	}
	n_read = read(fd, buffer, BUFFER_SIZE);
	buffer[n_read] = '\0';
	if (n_read == -1 || (n_read == 0 && ft_strlen_char(line, '\0') == 0))
		return (free(line), NULL);
	return (ft_read_loop(line, buffer, n_read, fd));
}
