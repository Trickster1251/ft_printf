#include "ft_printf.h"

void	ft_uputnbr(int n)
{
	int		mod;
	int		dif;
	int		chr;

	mod = 0;
	dif = 0;
	chr = 48;
	if (n == -2147483648)
	{
		ft_putstr_fd("2147483648", 1);
		return ;
	}
	else if (n < 0)
		n *= -1;
	mod = n % 10;
	dif = n / 10;
	if (dif != 0)
		ft_uputnbr(dif);
	chr += mod;
	write(1, &chr, 1);
}
