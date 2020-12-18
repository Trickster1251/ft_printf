#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_list
{
	char flag;
	char witdth;
	char dot;
	char precission;
	char type;
}       t_list;

int     ft_printf(const char	*s, ...);
char    *ft_parcer(char	*s, va_list ap, t_list va);
void    ft_is_flag(char **s);
int		ft_exist_type(char	*s);
void	ft_is_wight(char	**s, va_list ap);
void	ft_is_precission(char	**s, va_list ap);
void	ft_is_type(char	*s);
void	init_values(t_list *va);

#endif
