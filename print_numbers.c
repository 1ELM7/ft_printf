/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:00:12 by jmendez           #+#    #+#             */
/*   Updated: 2022/11/17 21:45:09 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsint(va_list arg, t_src *src, int tab[6])
{
	unsigned int	u;
	int				len;

	u = va_arg(arg, unsigned int);
	len = ft_unsintlen(u);
	if (tab[2] == 0 && u == 0)
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
		ft_put_unsint(u, src);
		if (-tab[0] > len && tab[2] >= 0)
			tab[0]--;
		if (tab[0] < 0 && tab[1] == 0)
			while (tab[0]++ < -len)
				ft_putchar(' ', src);
	}
}

static unsigned int	ft_check_sign(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static void	ft_printint_bis(int n, t_src *src, int tab[6], int len)
{
	if (tab[2] == 0 && n == 0)
		ft_particularbonus(tab, src);
	else
	{
		ft_spacebonus(tab, len, src);
		if (n < 0)
			ft_putchar('-', src);
		if (n >= 0 && tab[5])
			ft_putchar('+', src);
		if (tab[0] > 0 && tab[1] == 1 && tab[0] >= tab[2])
			while (tab[0] > len++)
				ft_putchar('0', src);
		else if (tab[2] > 0 && tab[2] != tab[0])
			while (tab[2] > len++)
				ft_putchar('0', src);
		ft_put_unsint(ft_check_sign(n), src);
		if (-tab[0] > len && tab[2] >= 0)
			tab[0]--;
		if (tab[0] < 0 && tab[1] == 0)
			while (tab[0]++ < -len)
				ft_putchar(' ', src);
	}
}

void	ft_printint(va_list arg, t_src *src, int tab[6])
{
	int	n;
	int	len;

	n = va_arg(arg, int);
	len = ft_unsintlen(ft_check_sign(n));
	if (n == -2147483648)
		len = 10;
	if (n < 0)
		len++;
	if (n < 0 && tab[2] > 0)
		tab[2]++;
	if (tab[2] == 0 && n == 0)
		ft_particularbonus(tab, src);
	else
	{
		if (tab[4] && n >= 0)
		{
			ft_putchar(' ', src);
			len++;
		}
		ft_printint_bis(n, src, tab, len);
	}
}
