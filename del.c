#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("rlen = %d", printf("r: %-10dh\n",1000));
	printf("mlen = %d", ft_printf("m: %-10dh\n",1000));
}