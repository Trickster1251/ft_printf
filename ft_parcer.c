#include "ft_printf.h"

void	init_values(t_list *va)
{
	va->flag = 0;
	va->witdth = 0;
	va->dot = 0;
	va->precission = 0;
	va->type = 0;
}

void     ft_is_flag(char **s)
{
	if (**s == '-')
		va.flag = '-';
	else if (**s == '0')
		va.flag = '0';
	(*s)++;
}

int		ft_exist_type(char	*s)
{
	if (*s == 'c' || *s == '%')
		return (1);
	return (0);
}

void	ft_is_wight(char	**s, va_list ap)
{
	if (**s == '*')
		va.witdth = va_arg(ap, int);
	else if (ft_isdigit(**s))
		va.witdth = ft_atoi(*s);
	(*s)++;
}

void	ft_is_precission(char	**s, va_list ap)
{
	(*s)++;
	if (**s == '*')
		va.precission = va_arg(ap, int);
	else if (ft_isdigit(**s))
		va.precission = ft_atoi(*s);
	else if (ft_exist_type(*s))
	{
		va.precission = 0;
		(*s)--;
	}
	(*s)++;
}

void	ft_is_type(char	*s)
{
	(*s == 'c') ? va.type = 'c' :
	(*s == '%') ? va.type = '%' : 0;
}

char  *ft_parcer(char	*s, va_list ap)
{
	int		len;

	len = 0;
	while (*s)
	{
		if (*s == '-' || *s == '0')
			ft_is_flag(&s);
		if (*s == '*' || ft_isdigit(*s))
			ft_is_wight(&s, ap);
		if (*s == '.')
			ft_is_precission(&s, ap);
		if (ft_exist_type(s))
			ft_is_type(s);
		break;
	}
	return (s);
}
