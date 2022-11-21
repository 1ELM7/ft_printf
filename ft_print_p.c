/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:29:28 by jmendez           #+#    #+#             */
/*   Updated: 2022/11/17 23:30:54 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkp(const char *f, unsigned long long p, t_src *src, int tab[6])
{
	if (!p && !tab[3] && *f == 'p')
	{
		write(1, "(nil)", 5);
		src->len += 5;
	}
	else if (*f == 'p' || (*f == 'x' && tab[3] && p != 0))
	{
		write(1, "0x", 2);
		src->len += 2;
	}
	else if (*f == 'X' && tab[3] && p != 0)
	{
		write(1, "0X", 2);
		src->len += 2;
	}
}

void	ft_print_p(const char *format, va_list arg, t_src *src, int tab[6])
{
	unsigned long long	p;
	int					len;

	p = va_arg(arg, unsigned long long);
	if (p)
		len = ft_hexalen(p) + 2;
	else
		len = 5;
	if (tab[0] > 0)
		while (tab[0]-- > len)
			ft_putchar(' ', src);
	ft_checkp(format, p, src, tab);
	if (p)
		ft_print_hexa(format, p, src);
	if (tab[0] < 0)
		while (tab[0]++ < -len)
			ft_putchar(' ', src);
}
