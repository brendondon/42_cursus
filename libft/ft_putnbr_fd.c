/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:22:35 by breda-si          #+#    #+#             */
/*   Updated: 2023/10/05 17:33:16 by breda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	if(n == -2147483647)
	{
		ft_putstr_fd("-2147483647", fd);
		return;
	}
	if(n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	if(n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10, fd);
}