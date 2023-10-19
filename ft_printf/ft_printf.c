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
#include <stdlib.h>

void	ft_putchar(char c, t_dados *data)
{
	write(1, &c, 1);
	data->count++;
}

void	ft_putstr(char *str, t_dados *data)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++], data);
}

void	ft_nbrbase(long long nb, t_dados *data)
{
	data->base = "0123456789abcdf";
	if (data->flag == 'x' || data->flag == 'p')
	{
		data->nbase = 16;
		data->base = "0123456789abcdef";
	}
	if (data->flag == 'X')
	{
		data->nbase = 16;
		data->base = "0123456789ABCDEF";
	}
	if (data->flag == 'i' || data->flag == 'd' || data->flag == 'u')
		data->nbase = 10;
	if (nb >= data->nbase)
	{
		ft_nbrbase(nb / data->nbase, data);
	}
	ft_putchar(data->base[nb % data->nbase], data);
}

void	ft_flags(const char *str, va_list arg, t_dados *data)
{
	data->flag = *str;
	if (*str == 'c' || *str == '%')
		ft_putchar(va_arg(arg, int), data);
	else if (*str == 's')
		ft_putstr(va_arg(arg, char *), data);
	else if (*str == 'd' || *str == 'i')
	{
		data->nbr = va_arg(arg, int);
		ft_nbrbase(data->nbr, data);
	}
	else if (*str == 'u' || *str == 'x' || *str == 'X')
	{
		data->nbr = va_arg(arg, unsigned int);
		ft_nbrbase(data->nbr, data);
	}
	else if (*str == 'p')
	{
		ft_putstr("0x", data);
		data->nbr = va_arg(arg, long);
		ft_nbrbase(data->nbr, data);
	}
}

int	ft_printf(const char *abc, ...)
{
	va_list	argss;
	t_dados	data;

	va_start (argss, abc);
	data.nbase = 16;
	data.count = 0;
	while (*abc)
	{
		if (*abc == '%')
		{
			abc++;
			ft_flags(abc, argss, &data);
			abc++;
		}
		else
			ft_putchar(*abc++, &data);
	}
	va_end(argss);
	return (data.count);
}
/*
int main(int argc, char const *argv[])
{
	int a;
	void *b;
	int *c;
	int *d;

	d = malloc(sizeof(int)*2);
	d[0] = a;
	b = (void *)d;
	c = &b;
	a = ft_printf("%c %s %d\n %p\n",'A', "boraa", 30000000000000000, d);
	printf("%d\n", 30000000000000000);
	printf("%p\n", c) ;
	printf("%p\n", b) ;
	free(d);
	return 0;
}*/
