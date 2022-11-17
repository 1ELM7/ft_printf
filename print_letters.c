/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:02:40 by jmendez           #+#    #+#             */
/*   Updated: 2022/11/15 19:39:35 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_s_bis(char *s, t_src *src, int tab[6])
{
	int	len;

	if (!s)
	{
		len = 0;
		if (tab[2] < 0 || tab[2] >= 6)
			ft_print_s_bis("(null)", src, tab);
	}
	else
	{
		len = ft_strlen(s);
		if (tab[2] >= 0 && tab[2] < len)
			len = tab[2];
		ft_spacebonus(tab, len, src);
		if (tab[2] >= 0 && tab[2] < ft_strlen(s))
			while (tab[2]--)
				ft_putchar(*s++, src);
		else
			ft_putstr(s, src);
		if (tab[0] < 0 && tab[1] == 0)
			while (tab[0]++ < -len)
				ft_putchar(' ', src);
	}
}

void	ft_print_s(va_list arg, t_src *src, int tab[6])
{
	char	*s;

	s = va_arg(arg, char *);
	ft_print_s_bis(s, src, tab);
}

void	ft_print_c(va_list arg, t_src *src, int tab[6])
{
	char	c;

	c = va_arg(arg, int);
	if (tab[2] > 1 && tab[0] > tab[2])
		while (tab[0]-- > tab[2])
			ft_putchar(' ', src);
	else if (tab[0] > tab[2] && tab[2] > 0)
		while (tab[0]-- > 1)
			ft_putchar(' ', src);
	else if (tab[0] > 0 && tab[1] == 0 && tab[0] > tab[2])
		while (tab[0]-- > 1)
			ft_putchar(' ', src);
	ft_putchar(c, src);
	if (tab[0]++ < -1)
		while (tab[0]++ < 0)
			ft_putchar(' ', src);
}
