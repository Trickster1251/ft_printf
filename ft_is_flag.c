/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 22:54:21 by walethea          #+#    #+#             */
/*   Updated: 2020/12/26 22:54:51 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_flag(char *s, t_list *va)
{
	int		i;

	i = 0;
	if (*s == '-')
		while (*s == '0' || *s == '-')
		{
			s++;
			i++;
		}
	va->flag = 1;
	if (*s == '0')
		while (*s == '0' || *s == '-')
		{
			if (*s == '-')
				va->flag = 1;
			else
				va->flag = 0;
			s++;
			i++;
		}
	return (i);
}
