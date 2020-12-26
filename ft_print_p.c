#include "ft_printf.h"

int		ft_numlen_p(unsigned long long num, t_list *va)
{
	int		len;

	len = 0;
    if (va->dot == 1 && va->precission == 0 && num == 0)
        return (2);
	else if (num == 0)
		return (3);
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len + 2);
}

void		ft_putnbr_p(unsigned long long n, t_list *va)
{
	unsigned long long		mod;
	unsigned long long		dif;
	char		chr;

	mod = 0;
	dif = 0;
	chr = 'a';
	mod = n % 16;
	dif = n / 16;

	if (dif != 0)
		ft_putnbr_p(dif, va);
	if (mod >= 10)
		ft_putchar_fd((mod + chr)-10,1);
	else
		ft_putchar_fd(mod + '0', 1);
}

int     ft_print_left_p(int len_num,t_list *va, unsigned long long num)
{
	int len;

	len = 0;

	len += ft_print_while(va->precission - (len_num - 2), '0');
    ft_putstr_fd("0x",1);
	if (va->precission == 0 && va->dot == 1 && num == 0)
		len_num--;
	else 
		ft_putnbr_p(num, va);

	len += ft_print_while(va->witdth - MAX(len_num, va->precission), ' ');
	return (len + len_num);
}

int     ft_print_right_p(int len_num,t_list *va, unsigned long long num)
{
	char    sym;
	int     len;
	len = 0;
	sym = ' ';


	if (va->flag == 0 && !(va->dot))
		sym = '0';
	len += ft_print_while(va->witdth - MAX(len_num, va->precission), sym);
    ft_putstr_fd("0x",1);
	len += ft_print_while(va->precission - (len_num - 2), '0');
	if (!(va->precission == 0 && va->dot == 1 && num == 0))
		ft_putnbr_p(num, va);
	return (len + len_num);
}

int     ft_print_p(va_list *argptr, t_list *va)
{
	int len;
	unsigned long num;
	int len_num;

	len = 0;
	len_num = ft_numlen_p(num = va_arg(*argptr, unsigned long long),va);
	if (va->flag == 1)
		len = ft_print_left_p(len_num, va, num);
	else
		len = ft_print_right_p(len_num, va, num);
	return (len);
}