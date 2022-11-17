/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:45:43 by jmendez           #+#    #+#             */
/*   Updated: 2022/11/15 20:44:31 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(const char *format)
{
	int	b;

	b = 0;
	if (ft_isdigit(*format))
		b = 1;
	else if (*format == '-')
		b = 1;
	else if (*format == '.')
		b = 1;
	else if (*format == ' ')
		b = 1;
	else if (*format == '+')
		b = 1;
	else if (*format == '#')
		b = 1;
	return (b);
}

void	ft_type_arg(va_list arg, const char *format, t_src *src)
{
	int	tab[6];

	ft_checkbonus(format, tab);
	ft_checkbonus_2(format, tab);
	while (ft_isflag(format))
		format++;
	if (*format == 'd' || *format == 'i')
		ft_printint(arg, src, tab);
	else if (*format == 's')
		ft_print_s(arg, src, tab);
	else if (*format == 'p')
		ft_print_p(arg, src, tab);
	else if (*format == 'x')
		ft_hexa_low(arg, src, tab);
	else if (*format == 'X')
		ft_hexa_up(arg, src, tab);
	else if (*format == '%')
		ft_print_percent(src);
	else if (*format == 'c')
		ft_print_c(arg, src, tab);
	else if (*format == 'u')
		ft_print_unsint(arg, src, tab);
	else
		return ;
	format++;
}
