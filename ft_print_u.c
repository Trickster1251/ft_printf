#include "ft_printf.h"

int		ft_putnbr_u(unsigned int n)
{
	int		mod;
	int		dif;
	int		chr;
	int		len;

	mod = 0;
	dif = 0;
	chr = 48;
	len = 1;
	mod = n % 10;
	dif = n / 10;
	if (dif != 0)
	{
		ft_putnbr_u(dif);
		len++;
	}
	chr += mod;
	write(1, &chr, 1);
	return (len);
}

int     ft_print_left_u(int len_num,t_list *va, int num)
{
	int len;

	len = 0;
	len += ft_print_while(va->precission - len_num, '0');
	if (va->precission == 0 && va->dot == 1 && num == 0)
		len_num--;
	else 
		ft_putnbr_u(num);
	len += ft_print_while(va->witdth - MAX(len_num, va->precission), ' ');
	return (len + len_num);
}

int     ft_print_right_u(int len_num,t_list *va, int num)
{
	char    sym;
	int     len;
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
	ft_putnbr_u(num);
	return (len + len_num);
}

int     ft_print_int_u(va_list *argptr, t_list *va)
{
	int len;
	long num;
	int len_num;

	len = 0;
	len_num = ft_numlen(num = va_arg(*argptr, unsigned int), va);
	if (va->flag == 1)
		len = ft_print_left_u(len_num, va, num);
	else
		len = ft_print_right_u(len_num, va, num);
	return (len);
}