/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:56:24 by breda-si          #+#    #+#             */
/*   Updated: 2023/10/26 15:43:25 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	ft_strlen(char *s);
char	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_charf(char *s);
char	*ft_strdup(char *s);
char	*next_line(char *temp);
char	*ft_get_line(char *temp);
char	*ft_buffer(char *buffer, char *temp, size_t bit);
char	*get_next_line(int fd);
#endif