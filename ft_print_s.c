/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:26:20 by walethea          #+#    #+#             */
/*   Updated: 2020/12/27 00:26:21 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_s_no_flag(t_list *va, int len_str, char *str)
{
	int len;

	len = 0;
	len += ft_print_while(((va->dot == 0) ? (va->witdth - len_str) :
		(va->witdth - MIN(len_str, va->precission))), ' ');
	if ((va->dot))
		len += write(1, str, (len_str > va->precission) ?
		va->precission : (len_str));
	else
		len += write(1, str, len_str);
	return (len);
}

int		ft_print_s(va_list *argptr, t_list *va)
{
	int		len;
	int		len_str;
	char	*str;

	len = 0;
	str = va_arg(*argptr, char *);
	(!str) ? (str = "(null)") : 0;
	len_str = ft_strlen(str);
	if (va->flag == 1)
	{
		if ((va->dot))
			len += write(1, str, ((len_str > va->precission) ?
			(va->precission) : (len_str)));
		else
			len += write(1, str, len_str);
		len += ft_print_while((va->dot == 0) ? (va->witdth - len_str) :
		(va->witdth - MIN(len_str, va->precission)), ' ');
	}
	else
		len += ft_print_s_no_flag(va, len_str, str);
	return (len);
}
