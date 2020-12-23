#include "ft_printf.h"
#include <stdio.h>

int     ft_print_flag(t_list *va, int len)
{
    int     spaces;
    int     space_len;

    space_len = 0;
    spaces = va->witdth -= len;
    if (va->flag == 1)
        while (spaces--)
            space_len += write(1," ",1);
    else if (va->flag == 0)
        while (spaces--)
            space_len += write(1,"0",1);
    return (space_len);
}

int     ft_print_char(va_list *argptr, t_list *va)
{
    char chr = (va->type == '%') ? '%' :
    va_arg(*argptr, int);
    write(1,&chr,1);
    return (1);
}

int     ft_print_while(int i, char chr)
{
    int     len;

    len = 0;
    while(i-- > 0)
    {
        len += write(1,&chr,1);
    }
    return (len);
}

int     ft_print_left(int len_num,t_list *va, int num)
{
    int len;

    len = 0;
    len += ft_print_while(va->precission - len_num, '0');
    ft_putnbr_fd(num, 1);
    len += ft_print_while(va->witdth - MAX(len_num, va->precission), ' ');
    return (len + len_num);
}

int     ft_print_right(int len_num,t_list *va, int num)
{
    char    sym;
    int     len;
    len = 0;
    sym = ' ';

    if (va->flag == 0 && !(va->precission))
        sym = '0';
    len += ft_print_while(va->witdth - MAX(len_num, va->precission), sym);
    len += ft_print_while(va->precission - len_num, '0');
    ft_putnbr_fd(num, 1);
    return (len + len_num);
}

int     ft_print_int(va_list *argptr, t_list *va)
{
    int len;
    int num;
    int len_num;

    len = 0;
    len_num = ft_numlen(num = va_arg(*argptr, int));
    if (va->flag == 1)
        len = ft_print_left(len_num, va, num);
    else
        len = ft_print_right(len_num, va, num);
    return (len);
}

int     ft_processor(t_list *va, va_list *argptr)
{
    int len;

    len = 0;
    if (va->type == 'd' || va->type == 'i')
        len += ft_print_int(argptr, va);  
    else if (va->type == 'c' || va->type == '%')
        len += ft_print_char(argptr, va);
    return (len);
}