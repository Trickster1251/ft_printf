#include <stdio.h>

typedef struct
{
	char flag;
	char witdth;
	char dot;
	char precission;
	char type;
}       g_list;

g_list va;

void     ft_is_flag(char *s)
{
	if (*s == '-')
		va.flag = '-';
	else if (*s == '0')
		va.flag = '0';
}

void	ft_is_type(char	*s)
{
	(*s == 'c') ? va.type = 'c' :
	(*s == '%') ? va.type = '%' : NULL;
}

int		parcer(char		*str)
{
	int len;

	len = 0;
	ft_is_flag(*s);
	s++;
	ft_is_type(*s);

}

int main()
{
    char    *s = "%-d";

    ft_is_flag(s);
    printf("%c\n", va.flag);

    printf("%0.5d\n", 10);
    // printf("%0-5.10d\n", 10);
    printf("%*d",50, 10);
}