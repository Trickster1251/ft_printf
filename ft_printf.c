# include "ft_printf.h"
# include <stdio.h>



int     ft_printf(const char *s, ...)
{
    int i;
    va_list  ap;
    t_list va;
    
    init_values(&va);
    i = 0;
    va_start(ap,s);
    while (*s)
    {
        if (*s == '%' && *(s+1) == '\0')
        {
            
            s = ft_parcer((char*)s, ap, va);
            s++;
        }
        else
            i += write(1, s++, 1);
    }
    printf("%c %c %c %c %c", va.flag, va.witdth, va.dot, va.precission, va.type);
    va_end(ap);
    return (i);
}

int main()
{

    ft_printf("Hello World %-0*.12c", 5, 'b');
    ft_printf("Hello\n");
    printf("Hello\n");
}