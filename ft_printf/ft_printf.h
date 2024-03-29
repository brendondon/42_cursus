/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:33:18 by marvin            #+#    #+#             */
/*   Updated: 2023/10/24 12:06:34 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

typedef struct s_dados
{
	int				count;
	unsigned int	nbase;
	char			*base;
	char			flag;
	long			nbr;
}	t_dados;

int	ft_printf(const char *abc, ...);

#endif