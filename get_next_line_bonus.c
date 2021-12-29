/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:00:37 by sgmira            #+#    #+#             */
/*   Updated: 2021/11/30 18:30:05 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

char	*read_buffer(int fd, char	*rest)
{
	int		i;
	char	*buff;

	i = 1;
	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (i && !ft_strchr_bonus(rest, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		rest = ft_strjoin_bonus(rest, buff);
	}
	free(buff);
	return (rest);
}

char	*get_line(char	*rest)
{
	int		i;
	char	*line;
	int		len;

	i = 0;
	if (!rest[0])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	len = i + 1;
	if (rest[i] == '\n')
		len++;
	line = (char *) malloc (len);
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_rest(char	*rest)
{
	int		i;
	int		len;
	char	*reste;

	i = 0;
	len = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free (rest);
		return (NULL);
	}
	i++;
	len = ft_strlen_bonus(&rest[i]);
	reste = (char *) malloc (len + 1);
	if (!reste)
		return (NULL);
	len = 0;
	while (rest[i] != '\0')
		reste[len++] = rest[i++];
	reste[len] = '\0';
	free (rest);
	return (reste);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reste[10240];

	if (fd < 0 || fd >= 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	reste[fd] = read_buffer(fd, reste[fd]);
	if (!reste[fd])
		return (NULL);
	line = get_line(reste[fd]);
	reste[fd] = get_rest(reste[fd]);
	return (line);
}
