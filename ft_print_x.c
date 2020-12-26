/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:46:21 by walethea          #+#    #+#             */
/*   Updated: 2020/12/27 00:46:22 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_numlen_x(unsigned int num)
{
	int		len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

void	ft_putnbr_x(unsigned int n, t_list *va)
{
	int		mod;
	int		dif;
	int		chr;

	mod = 0;
	dif = 0;
	chr = 'a';
	mod = n % 16;
	dif = n / 16;
	if (va->type == 'X')
		chr = 'A';
	if (dif != 0)
		ft_putnbr_x(dif, va);
	if (mod >= 10)
		ft_putchar_fd((mod + chr) - 10, 1);
	else
		ft_putchar_fd(mod + '0', 1);
}

int		ft_print_left_x(int len_num, t_list *va, int num)
{
	int len;

	len = 0;
	len += ft_print_while(va->precission - len_num, '0');
	if (va->precission == 0 && va->dot == 1 && num == 0)
		len_num--;
	else
		ft_putnbr_x(num, va);
	len += ft_print_while(va->witdth - MAX(len_num, va->precission), ' ');
	return (len + len_num);
}

int		ft_print_right_x(int len_num, t_list *va, int num)
{
	char	sym;
	int		len;

	len = 0;
	sym = ' ';
	if (va->precission == 0 && va->dot == 1 && num == 0)
		len_num--;
	if (va->flag == 0 && !(va->dot))
		sym = '0';
	len += ft_print_while(va->witdth - MAX(len_num, va->precission), sym);
	len += ft_print_while(va->precission - len_num, '0');
	if (va->precission == 0 && va->dot == 1 && num == 0)
		return (len);
	ft_putnbr_x(num, va);
	return (len + len_num);
}

int		ft_print_x(va_list *argptr, t_list *va)
{
	int len;
	int num;
	int len_num;

	len = 0;
	num = va_arg(*argptr, unsigned int);
	len_num = ft_numlen_x(num);
	if (va->flag == 1)
		len = ft_print_left_x(len_num, va, num);
	else
		len = ft_print_right_x(len_num, va, num);
	return (len);
}
