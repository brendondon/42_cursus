/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:49:13 by breda-si          #+#    #+#             */
/*   Updated: 2023/11/18 22:01:03 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
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