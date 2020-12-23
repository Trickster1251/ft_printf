/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:59:44 by walethea          #+#    #+#             */
/*   Updated: 2020/12/22 20:42:56 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int		ft_putnbr_fd(int n, int fd)
{
	int		mod;
	int		dif;
	int		chr;
	int		len;

	mod = 0;
	dif = 0;
	chr = 48;
	len = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (10);
	}
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
		len++;
	}
	mod = n % 10;
	dif = n / 10;
	if (dif != 0)
	{
		ft_putnbr_fd(dif, fd);
		len++;
	}
	chr += mod;
	write(fd, &chr, 1);
	return (len);
}
