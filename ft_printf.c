#include "ft_printf.h"

void	init_values(t_list *va)
{
	va->flag = 2;
	va->witdth = 0;
	va->precission = 0;
	va->negative = 0;
	va->dot = 0;
	va->type = 0;
}

int		ft_printf(const char	*str, ...)
{
	int		len;
	t_list  va;
	va_list argptr;
	len = 0;
	va_start(argptr, str);
	while(*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			init_values(&va);
			str = ft_parser((char*)str, &va, &argptr);
			len += ft_processor(&va, &argptr);
		}
		else
			len += write(1,str++,1);
	}
	va_end(argptr);
	return (len);
}