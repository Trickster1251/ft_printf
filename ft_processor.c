/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:50:01 by walethea          #+#    #+#             */
/*   Updated: 2020/12/27 00:50:05 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_while(int i, char chr)
{
	int		len;

	len = 0;
	while ((i--) > 0)
	{
		len += write(1, &chr, 1);
	}
	return (len);
}

int		ft_processor(t_list *va, va_list *argptr)
{
	int len;

	len = 0;
	if (va->type == 'd' || va->type == 'i')
		len += ft_print_int(argptr, va);
	else if (va->type == 'u')
		len += ft_print_int_u(argptr, va);
	else if (va->type == 'x' || va->type == 'X')
		len += ft_print_x(argptr, va);
	else if (va->type == 'p')
		len += ft_print_p(argptr, va);
	else if (va->type == 's')
		len += ft_print_s(argptr, va);
	else if (va->type == 'c' || va->type == '%')
		len += ft_print_c(argptr, va);
	return (len);
}
