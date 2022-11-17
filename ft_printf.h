/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:02:31 by jmendez           #+#    #+#             */
/*   Updated: 2022/11/17 19:08:54 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_src
{
	int	len;
	int	width;
}				t_src;

void		ft_putchar(char c, t_src *src);
void		ft_putstr(char *s, t_src *src);
void		ft_putint(int n, t_src *src);
void		ft_put_unsint(unsigned int n, t_src *src);

int			ft_hexalen(unsigned long long n);
int			ft_unsintlen(unsigned int n);
int			ft_strlen(const char *str);

void		ft_checkp(char f, unsigned long long p, t_src *src, int tab[6]);
void		ft_print_p(va_list arg, t_src *src, int tab[6]);

void		ft_print_hexa(char format, unsigned long long x, t_src *src);
void		ft_hexalow_bonus(int tab[6], t_src *src, unsigned long long x);
void		ft_hexa_low(va_list arg, t_src *src,
				int tab[6]);
void		ft_hexa_up(va_list arg, t_src *src, int tab[6]);

void		ft_print_unsint(va_list arg, t_src *src, int tab[6]);
void		ft_printint(va_list arg, t_src *src, int tab[6]);

void		ft_print_s(va_list arg, t_src *src, int tab[6]);
void		ft_print_c(va_list arg, t_src *src, int tab[6]);

void		ft_print_percent(t_src *src);

const char	*ft_find_arg(t_src *src, const char *format);

int			ft_isflag(const char *format);
void		ft_type_arg(va_list arg, const char *format, t_src *src);

int			ft_printf(const char *format, ...);

void		ft_particularbonus(int tab[6], t_src *src);
void		ft_spacebonus(int tab[6], int len, t_src *src);
void		ft_checkbonus(const char *format, int tab[6]);
void		ft_checkbonus_2(const char *format, int tab[6]);

int			ft_atoi(const char *str);
int			ft_isdigit(int c);

#endif
