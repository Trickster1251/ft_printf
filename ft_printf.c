#include "ft_printf.h"
#include <stdio.h>

void	init_values(t_list *va)
{
	va->flag = 0;
	va->witdth = 0;
	va->precission = 0;
	va->type = 0;
}


int		ft_printf(const char	*str, ...)
{
	int		len;
	t_list  va;
	va_list argptr;
	len = 0;
	va_start(argptr, str);
	init_values(&va);
	while(*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str = ft_parser((char*)str, &va, &argptr);
			len += ft_processor(&va, &argptr);
		}
		else
			len += write(1,str++,1);
	}
	// printf("\nflag : %d\n", va.flag);
	// printf("wight : %d\n", va.witdth);
	// printf("pressicion : %d\n", va.precission);
	// printf("type : %c\n", va.type);
	va_end(argptr);
	return (len);
}

// int main()
// {
// // 	// printf("Hello World\n    %2c\n", 'c');
// // 	// printf("%d", ft_printf("Hello World %d", 200));

// // 	// printf("%d", ft_printf("hello %%\n"));
// // 	// printf("%d", printf("hello %%\n"));
// // 	// flag -  форматирует вывод по левому краю (пробела после числа)
// // 	// флаг 0 - заполняет нулями до (ширина - количество символов) если есть точность флаг скидывается на дефолтный
// // 	// дефолтный флаг форматирует вывод по правому краю (пробелы до числа)
// // 	// вывод ширины = ширина - (количество символов + (число точности - количество символов))
// // 	// если в ширине есть минус то минус становится флагом
// // 	// если есть точность то добавляем нули перед числом // точность = число точности - кол символов
// // 	// если точность минусовая то она становится 0
// // 	// printf("Hello World %-10.5d_hello", 10);
// }