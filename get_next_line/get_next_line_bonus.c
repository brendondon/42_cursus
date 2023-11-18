/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:48:26 by breda-si          #+#    #+#             */
/*   Updated: 2023/11/18 22:11:16 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *temp)
{
	size_t	size;
	size_t	i;
	char	*ret;

	if (temp[0] == '\0')
		return (NULL);
	else if (temp[0] == '\n')
		return (ft_strdup("\n"));
	else if (ft_charf(temp) != 0)
		size = ft_charf(temp) + 1;
	else
		size = ft_strlen(temp) + 1;
	ret = ft_calloc(sizeof(char), size + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size - 1 && temp[i])
	{
		ret[i] = temp[i];
		i++;
	}
	if (ft_charf(temp) != 0)
		ret[i] = '\n';
	return (ret);
}

char	*ft_buffer(char *buffer, char *temp, size_t bit)
{
	char	*ret;
	size_t	i;

	ret = ft_calloc(sizeof(char), (bit + ft_strlen(temp) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	if (temp)
	{
		while (temp[i])
		{
			ret[i] = temp[i];
			i++;
		}
	}
	i = 0;
	while (i < bit)
	{
		ret[i + ft_strlen(temp)] = buffer[i];
		i++;
	}
	free(temp);
	return (ret);
}

int	ft_complete(char **temp, char **buffer, int *bit, int fd)
{
	while (*bit > 0 && ft_charf(*buffer) == 0 && ft_charf(*temp) == 0)
	{
		*bit = read(fd, *buffer, BUFFER_SIZE);
		if (*bit == 0)
			break ;
		if (*bit == -1)
		{
			free (*temp);
			*temp = NULL;
			free (*buffer);
			return (0);
		}
		*temp = ft_buffer(*buffer, *temp, *bit);
	}
	return (1);
}

char	*ft_line(int fd)
{
	int			bit;
	char		*buffer;
	static char	*temp[FOPEN_MAX];

	bit = 1;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!ft_complete(&temp[fd], &buffer, &bit, fd))
		return (NULL);
	if (bit == 0 && !buffer[0] && !temp[fd])
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	buffer = ft_get_line(temp[fd]);
	temp[fd] = next_line(temp[fd]);
	if (!temp[fd])
		free(temp[fd]);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	line = ft_line(fd);
	return (line);
}
