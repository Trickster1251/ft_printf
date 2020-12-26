/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 23:55:20 by walethea          #+#    #+#             */
/*   Updated: 2020/12/26 23:55:21 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(va_list *argptr, t_list *va)
{
	int		len;
	char	chr;

	len = 0;
	chr = (va->type == '%') ? '%' :
	va_arg(*argptr, int);
	if (va->type == '%' && va->flag == 0)
	{
		len += ft_print_while((va->witdth - 1), '0');
		ft_putchar_fd(chr, 1);
	}
	else if (va->flag == 2)
	{
		len += ft_print_while((va->witdth - 1), ' ');
		ft_putchar_fd(chr, 1);
	}
	else if (va->flag == 1)
	{
		ft_putchar_fd(chr, 1);
		len += ft_print_while((va->witdth - 1), ' ');
	}
	return (len + 1);
}
