/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:00:03 by jmendez           #+#    #+#             */
/*   Updated: 2022/11/18 18:17:32 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_particularbonus(int tab[6], t_src *src)
{
	if (tab[0] > 0)
		while (tab[0]-- > 0)
			ft_putchar(' ', src);
	else if (tab[0] < 0)
		while (tab[0]++ < 0)
			ft_putchar(' ', src);
}

void	ft_spacebonus(int tab[6], int len, t_src *src)
{
	if (tab[2] > len && tab[0] > tab[2])
		while (tab[0]-- > tab[2])
			ft_putchar(' ', src);
	else if (tab[0] > tab[2] && tab[2] > 0)
		while (tab[0]-- > len)
			ft_putchar(' ', src);
	else if (tab[0] > 0 && tab[1] == 0 && tab[0] > tab[2])
	{
		while (tab[0] > len)
		{
			ft_putchar(' ', src);
			tab[0]--;
		}
	}
}

void	ft_checkbonus(const char *format, int tab[6])
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = -1;
	ft_checkbonus_2(format, tab);
	while (*format == ' ' || *format == '#' || *format == '+')
		format++;
	while ((*format == '-') && (*(format + 1) == '-'))
		format++;
	if (ft_isdigit(*format) || (*format == '-'))
		tab[0] = ft_atoi(format);
	if (*format == '0')
		tab[1] = 1;
	while (ft_isdigit(*format) || (*format == '-'))
		format++;
	if (*format == '.')
		tab[2] = ft_atoi(++format);
}

void	ft_checkbonus_2(const char *format, int tab[6])
{
	tab[3] = 0;
	tab[4] = 0;
	tab[5] = 0;
	while (ft_isflag(format))
	{
		if (*format == '#')
			tab[3] = 1;
		if (*format == ' ')
			tab[4] = 1;
		if (*format == '+')
			tab[5] = 1;
		format++ ;
	}
}
