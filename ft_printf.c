/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:11:06 by jmendez           #+#    #+#             */
/*   Updated: 2022/11/15 20:27:23 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pass(const char *format)
{
	int	i;

	i = 0 ;
	while (ft_isflag(format))
	{
		i++;
		format++;
	}
	if (*format != '\0')
		i++;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	t_src	src;

	va_start(arg, format);
	src.len = 0;
	src.width = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ft_type_arg(arg, ++format, &src);
			format += ft_pass(format);
		}
		else
			format = ft_find_arg(&src, format);
		if (!format)
		{
			src.len += write(1, "(null)", 6);
			break ;
		}
	}
	va_end(arg);
	return (src.len);
}
