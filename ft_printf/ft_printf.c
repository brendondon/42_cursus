/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:59:43 by marvin            #+#    #+#             */
/*   Updated: 2023/10/19 22:44:27 by breda-si         ###   ########.fr       */
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

void	ft_nbrbase(unsigned long nb, t_dados *data)
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
		ft_nbrbase(nb / data->nbase, data);
	ft_putchar(data->base[nb % data->nbase], data);
}

void	ft_flags(const char *str, va_list arg, t_dados *data)
{
	data->flag = *str;
	if (*str == 'c')
		ft_putchar(va_arg(arg, int), data);
	else if (*str == 's')
		ft_putstr(va_arg(arg, char *), data);
	else if (*str == 'd' || *str == 'i')
	{
		data->nbr = va_arg(arg, int);
		if(data->nbr < 0)
		{
			ft_putchar('-', data);
			data->nbr *= -1;
		}
		ft_nbrbase(data->nbr, data);
	}
	else if (*str == 'u' || *str == 'x' || *str == 'X')
	{
		data->nbr = va_arg(arg, unsigned int);
		ft_nbrbase(data->nbr, data);
	}
	else if (*str == 'p')
	{
		data->nbr = va_arg(arg, long);
		if(data->nbr == 0)
			return (ft_putstr("(nil)", data));
		ft_putstr("0x", data);
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
		if (*(abc+1) == '%' && *abc == '%')
			ft_putchar(*(++abc), &data);
		else if (*abc == '%' && *(abc + 1) != '%')
			ft_flags(++abc, argss, &data);
		else if(*abc != '%')
			ft_putchar(*abc, &data);
		abc++;
	}
	va_end(argss);
	return (data.count);
}

#include<limits.h>

int main(int argc, char const *argv[])
{
	ft_printf(" %p \n", -LONG_MAX);
	printf(" %p \n", -LONG_MAX);
}