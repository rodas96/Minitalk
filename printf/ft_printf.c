/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorais <rmorais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:31:07 by rmorais           #+#    #+#             */
/*   Updated: 2022/11/29 14:56:21 by rmorais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_variables(char variable, va_list arg, int plus)
{
	if (variable == 'c')
		return (ft_printchar(va_arg(arg, int)));
	else if (variable == 's')
		return (ft_printstr(va_arg(arg, char *)));
	else if (variable == 'p')
		return (ft_printnbrbase((va_arg(arg, unsigned long)), HEXAL, 0, 'p'));
	else if (variable == 'd' || variable == 'i')
		return (ft_printnbr(va_arg(arg, int), plus));
	else if (variable == 'u')
		return (ft_printnbrbase(va_arg(arg, unsigned int), DEC, 0, 'u'));
	else if (variable == 'x')
		return (ft_printnbrbase(va_arg(arg, unsigned int), HEXAL, 0, 'x'));
	else if (variable == 'X')
		return (ft_printnbrbase(va_arg(arg, unsigned int), HEXAU, 0, 'X'));
	else if (variable == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		count;
	int		plus;

	count = 0;
	va_start(arg, s);
	while (*s)
	{
		if (*s == '%')
		{
			plus = 0;
			if (*++s == '+')
			{
				plus = 1;
				s++;
			}
			count += ft_variables(*s, arg, plus);
			s++;
		}
		else
			count += ft_printchar(*s++);
	}
	va_end(arg);
	return (count);
}
