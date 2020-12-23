#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define	MAX(a, b) (((a) > (b)) ? (a) : (b))
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list
{
	int		flag;
	int		witdth;
	int		precission;
	char	type;
}			t_list;

int     ft_printf(const char	*s, ...);
int     ft_processor(t_list *va, va_list *argptr);
char	*ft_parser(char	*str, t_list *va, va_list *argptr);
int     ft_is_flag(char *s, t_list *va);
int		ft_numlen(long num);
int		ft_is_wight(char	*s, t_list *va, va_list *argptr);
int		ft_exist_type(char	*s);
int		ft_is_type(char	*s, t_list *va);
int		ft_is_precission(char	*s, t_list *va, va_list *argptr);
void	init_values(t_list *va);
int		ft_parcer(char	*s, t_list *va);


#endif
