/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:28:28 by marvin            #+#    #+#             */
/*   Updated: 2023/10/30 23:28:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_line(int fd)
{
	int			bit;
	char		*buffer;
	static char	*temp = NULL;

	bit = 1;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bit > 0 && ft_charf(buffer) == 0 && ft_charf(temp) == 0)
	{
		bit = read(fd, buffer, BUFFER_SIZE);
		if (bit == 0)
			break ;
		if (bit == -1)
		{
			free(buffer);
			return (NULL);
		}
		temp = ft_buffer(buffer, temp, bit);
	}
	if (bit == 0 && !buffer[0] && !temp)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	buffer = ft_get_line(temp);
	temp = next_line(temp);
	if (!temp)
		free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_line(fd);
	return (line);
}

int main(int ac, char **av)
{
	char *a;
	int fd = open(av[1], O_RDONLY);
	a = get_next_line(fd);
	printf("%s", a);
	free(a);
	a = get_next_line(fd);
	printf("%s", a);
	free(a);	
	close(fd);
	fd = open(av[1], O_RDONLY);
	a = get_next_line(fd);
	printf("%s", a);
	free(a);
	a = get_next_line(fd);
	printf("%s", a);
	free(a);
	
	return 0;
}

