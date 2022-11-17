/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:45:16 by jmendez           #+#    #+#             */
/*   Updated: 2022/11/10 09:07:37 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			return ((char *)(s + i));
		i++;
	}
	if (!s)
		return ((char *)s);
	return (0);
}

const char	*ft_find_arg(t_src *src, const char *format)
{
	char	*next;

	next = ft_strchr(format);
	if (next)
		src->width = next - format;
	else
		src->width = ft_strlen(format);
	write(1, format, src->width);
	src->len += src->width;
	while (*format && *format != '%')
		++format;
	return (format);
}
