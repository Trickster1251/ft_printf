#include "ft_printf.h"

int     ft_is_flag(char *s, t_list *va)
{
	//Флаг '-' = 1
	//Флаг '0' = 0
	//Флаг '- и 0' = 2
	int		i;

	i = 2;
// Сделать флаги интами, и должен быть дефолтный флаг = 2 флага
	i = 0;
	if (*s == '-')
	{
		while(*s == '0' || *s == '-')
		{
			s++;
			i++;
		}
		va->flag = 1;
	}
	if (*s == '0')
	{
		while(*s == '0' || *s == '-')
		{
			if (*s == '-')
				va->flag = 2;
			else
				va->flag = 0;
		s++;
		i++;
		}
	}
	return (i);
}