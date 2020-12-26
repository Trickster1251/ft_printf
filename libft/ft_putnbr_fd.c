/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:59:44 by walethea          #+#    #+#             */
/*   Updated: 2020/12/26 23:42:09 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int		mod;
	int		dif;
	int		len;

	mod = 0;
	dif = 0;
	len = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
		n *= -1;
	mod = n % 10;
	dif = n / 10;
	if (dif != 0)
		ft_putnbr_fd(dif, fd);
	ft_putchar_fd(mod + '0', 1);
}
