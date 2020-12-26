/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:38:58 by walethea          #+#    #+#             */
/*   Updated: 2020/12/26 21:39:00 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define MIN(a, b) (((a) < (b)) ? (a) : (b))

typedef struct	s_list
{
	int		flag;
	int		witdth;
	int		precission;
	int		negative;
	int		dot;
	char	type;
}				t_list;

int		ft_printf(const char *s, ...);
int		ft_processor(t_list *va, va_list *argptr);
char	*ft_parser(char	*str, t_list *va, va_list *argptr);
int		ft_print_x(va_list *argptr, t_list *va);
int		ft_print_p(va_list *argptr, t_list *va);
int		ft_print_c(va_list *argptr, t_list *va);
int		ft_print_s(va_list *argptr, t_list *va);
int		ft_print_int(va_list *argptr, t_list *va);
int		ft_is_flag(char *s, t_list *va);
int		ft_numlen(long num, t_list *va);
int		ft_is_precission(char *s, t_list *va, va_list *argptr);
int		ft_print_int_u(va_list *argptr, t_list *va);
int		ft_print_while(int i, char chr);
void	ft_uputnbr(int n);
#endif
