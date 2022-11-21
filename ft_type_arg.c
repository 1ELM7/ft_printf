/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:45:43 by jmendez           #+#    #+#             */
/*   Updated: 2022/11/21 16:22:26 by jmendez          ###   ########.fr       */
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

static int	ft_istreated(const char *format)
{
	int	b;

	b = 0;
	if (*format == 'd' || *format == 'i')
		b = 1;
	else if (*format == 's' || *format == 'c')
		b = 1;
	else if (*format == 'p' || *format == 'u')
		b = 1;
	else if (*format == 'x' || *format == 'X')
		b = 1;
	else if (*format == '%')
		b = 1;
	return (b);
}

void	ft_type_arg(va_list arg, const char *format, t_src *src)
{
	int	tab[6];

	ft_checkbonus(format, tab);
	while (ft_isflag(format))
		format++;
	if (*format == 'd' || *format == 'i')
		ft_printint(arg, src, tab);
	else if (*format == 's')
		ft_print_s(arg, src, tab);
	else if (*format == 'p')
		ft_print_p(format, arg, src, tab);
	else if (*format == 'x' || *format == 'X')
		ft_hexa_low(format, arg, src, tab);
	else if (*format == '%')
		ft_print_percent(src);
	else if (*format == 'c')
		ft_print_c(arg, src, tab);
	else if (*format == 'u')
		ft_print_unsint(arg, src, tab);
	else if (!(*format) || *format == '\0')
		src->len = -1;
	if (!(ft_istreated(format)) || (*format == '\0') || !(*format))
		return ;
	format++;
}
