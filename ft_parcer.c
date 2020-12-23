#include "ft_printf.h"
#include <stdio.h>


int		ft_numlen(long num)
{
	int		len;

	len = 0;
	if (num < 0 && (num *= -1))
		len++;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int		ft_exist_type(char	*s)
{
	if (*s == 'c' || *s == '%' || *s == 'd' || *s == 'i')
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
		len = ft_numlen(va->witdth);
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
	return (1);
}


int		ft_is_precission(char	*s, t_list *va, va_list *argptr)
{
	s++;
	int		len;

	len  = 1;
	
	// printf("\n%s", s);
	// if (va->flag == 0)
	// 	{
	// 		va->flag = //Сделать флаг делолтным
	// 	}
	if (*s == '*')
	{
		va->precission = va_arg(*argptr, int);
		++len;
	}
	else if (ft_isdigit(*s)) // нулевая точность может быть, учитывать от 0 до 9
	{
		va->precission = ft_atoi(s);
		len += ft_numlen(va->precission);
	}
	else
		va->precission = 0;
	return (len);
}

char	*ft_parser(char	*str, t_list *va, va_list *argptr)
{
		// printf("\n%c", va->flag);
		if (*(++str) == '-' || *str == '0')
			str += ft_is_flag(str, va);
		if (*str == '*' || ft_isdigit(*str))
			str += ft_is_wight(str, va, argptr);
		if (*str == '.')
			str += ft_is_precission(str, va, argptr);
		if (ft_exist_type(str))
			str += ft_is_type(str, va);
	return (str);
}