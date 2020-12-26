#include "ft_printf.h"

int     ft_print_left(int len_num,t_list *va, int num)
{
	int len;

	len = 0;
	
	if (va->negative == 1)
	{
		len_num++;
		ft_putchar_fd('-', 1);
		va->precission += 1;
	}
	len += ft_print_while(va->precission - len_num, '0');
	if (va->precission == 0 && va->dot == 1 && num == 0)
		len_num--;
	else ft_uputnbr(num);
	len += ft_print_while(va->witdth - MAX(len_num, va->precission), ' ');
	return (len + len_num);
}

int     ft_print_right(int len_num,t_list *va, int num)
{
	char    sym;
	int     len;
	len = 0;
	sym = ' ';

	if (va->precission == 0 && va->dot == 1 && num == 0)
		len_num--;
	if (va->flag == 0 && !(va->dot))
		sym = '0';
	if (va->negative == 1 && sym == '0')
	{
		ft_putchar_fd('-', 1);
	}
	if (va->negative == 1)
	{
		va->precission++;
		len_num++;
	}
	len += ft_print_while(va->witdth - MAX(len_num, va->precission), sym);
	if (va->negative == 1 && sym != '0')
		ft_putchar_fd('-', 1);
	len += ft_print_while(va->precission - len_num, '0');
	if (va->precission == 0 && va->dot == 1 && num == 0)
		return (len);
	ft_uputnbr(num);
	return (len + len_num);
}


int     ft_print_int(va_list *argptr, t_list *va)
{
	int len;
	long long num;
	int len_num;

	len = 0;
	len_num = ft_numlen(num = va_arg(*argptr, int),va);
	if (num < 0)
	{
		va->negative = 1;
		num *= -1;
	}
	if (va->flag == 1)
		len = ft_print_left(len_num, va, num);
	else
		len = ft_print_right(len_num, va, num);
	return (len);
}
