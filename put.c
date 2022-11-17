/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:42:54 by jmendez           #+#    #+#             */
/*   Updated: 2022/11/06 11:54:38 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_src *src)
{
	write(1, &c, 1);
	src->len++;
}

void	ft_putstr(char *s, t_src *src)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], src);
		i++;
	}
}

void	ft_putint(int n, t_src *src)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		src->len += 11;
		return ;
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48, src);
	else if (n < 0)
	{
		ft_putchar('-', src);
		ft_putint(-n, src);
	}
	else
	{
		ft_putint(n / 10, src);
		ft_putint(n % 10, src);
	}
}

void	ft_put_unsint(unsigned int n, t_src *src)
{
	if (n <= 9)
		ft_putchar(n + 48, src);
	else
	{
		ft_put_unsint(n / 10, src);
		ft_put_unsint(n % 10, src);
	}
}
