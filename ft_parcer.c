/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:47:54 by walethea          #+#    #+#             */
/*   Updated: 2020/12/26 21:48:09 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_numlen(long num, t_list *va)
{
	int		len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0 && (va->type == 'd' || va->type == 'i'))
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int		ft_exist_type(char	*s)
{
	if (*s == 'c' || *s == '%' || *s == 'd' || *s == 'i' ||
	*s == 'u' || *s == 'x' || *s == 'X' || *s == 'p' || *s == 's')
		return (1);
	return (0);
}

int		ft_is_wight(char	*s, t_list *va, va_list *argptr)
{
	int len;

	len = 1;
	if (*s == '*')
		va->witdth = va_arg(*argptr, int);
	else if (ft_isdigit(*s))
	{
		va->witdth = ft_atoi(s);
		len = ft_numlen(va->witdth,va);
	}
	return (len);
}

int	ft_is_type(char	*s, t_list *va)
{
	if (*s == 'c')
		va->type = 'c';
	else if (*s == 'd')
		va->type = 'd';
	else if (*s == 'i')
		va->type = 'i';
	else if (*s == 's')
		va->type = 's';
	else if (*s == 'x')
		va->type = 'x';
	else if (*s == 'X')
		va->type = 'X';
	else if (*s == '%')
		va->type = '%';
	else if (*s == 'u')
		va->type = 'u';
	else if (*s == 'p')
		va->type = 'p';
	return (1);
}


int		ft_is_precission(char	*s, t_list *va, va_list *argptr)
{
	s++;
	int		len;

	len  = 1;
	
	va->dot = 1;
	if (*s == '*')
	{
		va->precission = va_arg(*argptr, int);
		++len;
	}
	else if (ft_isdigit(*s))
	{
		va->precission = ft_atoi(s);
		while (ft_isdigit(*(s++)))
			len++;
	}
	else
	{
		va->dot = 1;
		va->precission = 0;
	}
	return (len);
}

char	*ft_parser(char	*str, t_list *va, va_list *argptr)
{
		if (*(++str) == '-' || *str == '0')
			str += ft_is_flag(str, va);
		if (*str == '*' || ft_isdigit(*str))
			str += ft_is_wight(str, va, argptr);
		if (*str == '.')
			str += ft_is_precission(str, va, argptr);
		if (ft_exist_type(str))
			str += ft_is_type(str, va);
		if (va->witdth < 0)
    	{
        	va->witdth *= -1;
        	va->flag = 1;
    	}
		if (va->precission < 0)
		{
			va->dot = 0;
			va->precission = 0;
		}
	return (str);
}
