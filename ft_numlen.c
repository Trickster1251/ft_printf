/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walethea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:42:19 by walethea          #+#    #+#             */
/*   Updated: 2020/12/27 00:42:29 by walethea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_numlen(long num, t_list *va)
{
	int		len;

	len = 0;
	if (num == 0)
		return (1);
	else if (num < 0 && (va->type == 'd' || va->type == 'i'))
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}
