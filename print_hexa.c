/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:58:10 by jmendez           #+#    #+#             */
/*   Updated: 2022/11/21 16:57:17 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa(const char *format, unsigned long long x, t_src *src)
{
	char			*hexa_low;
	char			*hexa_up;

	hexa_low = "0123456789abcdef";
	hexa_up = "0123456789ABCDEF";
	if (*format == 'X')
	{
		if (x < 16)
			ft_putchar(hexa_up[x], src);
		else
		{
			ft_print_hexa(format, x / 16, src);
			ft_print_hexa(format, x % 16, src);
		}
	}
	else
	{
		if (x < 16)
			ft_putchar(hexa_low[x], src);
		else
		{
			ft_print_hexa(format, x / 16, src);
			ft_print_hexa(format, x % 16, src);
		}
	}
}

void	ft_hexalow_bonus(const char *format, int tab[6], t_src *src,
		unsigned int x)
{
	int	len;

	len = ft_unsintlen(x);
	if (tab[0] > 0 && tab[1] == 1 && tab[0] >= tab[2])
		while (tab[0] > len++)
			ft_putchar('0', src);
	else if (tab[2] > 0 && tab[2] != tab[0])
		while (tab[2] > len++)
			ft_putchar('0', src);
	ft_print_hexa(format, x, src);
	if (-tab[0] > len && tab[2] >= 0)
		tab[0]--;
	if (tab[0] < 0 && tab[1] == 0)
		while (tab[0]++ < -len)
			ft_putchar(' ', src);
}

static void	ft_end_bonus_hexa(t_src *src, int tab[6], int len)
{
	if (-tab[0] > len && tab[2] >= 0)
			tab[0]--;
	if (tab[0] < 0 && tab[1] == 0)
		while (tab[0]++ < -len)
			ft_putchar(' ', src);
}

void	ft_hexa_low(const char *format, va_list arg, t_src *src, int tab[6])
{
	unsigned int	x;
	int				len;

	x = va_arg(arg, unsigned int);
	len = ft_hexalen(x);
	if (tab[3])
		len += 2;
	if (tab[2] == 0 && x == 0)
		ft_particularbonus(tab, src);
	else
	{
		ft_spacebonus(tab, len, src);
		if (tab[0] > 0 && tab[1] == 1 && tab[0] >= tab[2])
			while (tab[0] > len++)
				ft_putchar('0', src);
		else if (tab[2] > 0 && tab[2] != tab[0])
			while (tab[2] > len++)
				ft_putchar('0', src);
		ft_checkp(format, x, src, tab);
		ft_print_hexa(format, x, src);
		ft_end_bonus_hexa(src, tab, len);
	}
}
