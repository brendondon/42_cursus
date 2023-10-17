/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:59:43 by marvin            #+#    #+#             */
/*   Updated: 2023/10/10 19:59:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void ft_putchar(char c, t_dados *data)
{
	write(1, &c, 1);
	data->count++;
}

void ft_putstr(char *str, t_dados *data)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++], data);
}

void 	ft_nbrbase(t_dados *data)
{
		
}
void	ft_flags(const char *str, va_list arg, t_dados *data)
{
	data->flag = *str;
	if (*str == 'c' || *str == '%')
		ft_putchar(va_arg(arg, int), data);
	else if (*str == 's')
		ft_putstr(va_arg(arg, char*), data);
	else if (*str == 'p' || *str == 'd' || *str == 'i'|| *str == 'u' || *str == 'x' || *str == 'X')
	{
		data->nbr = va_arg(arg, int);
		ft_nbrbase(data);
	}	
}

int ft_printf(const char *abc, ...)
{
	va_list argss;
	va_start(argss, abc);
	t_dados data;

	data.count = 0;
	while (*abc)
	{
		if(*abc == '%')
		{
			abc++;
			ft_flags(abc, argss, &data);
			abc++;
		}
		else
			ft_putchar(*abc++, &data);
	}
	va_end(argss);
	return(data.count);
}

/*int main(int argc, char const *argv[])
{
	int a;
	a = ft_printf("%c %s %i",'A', "boraa", 158749);
	printf("%d", a);
	return 0;
}*/
