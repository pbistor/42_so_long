/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:31:59 by vprieto-          #+#    #+#             */
/*   Updated: 2022/10/21 16:31:59 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *s, ...)
{
	va_list	ap;
	int		i;
	int		t;

	t = 0;
	i = 0;
	va_start(ap, s);
	while (s[i] != 0)
	{
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			t++;
		}	
		else
		{
			i++;
			t += ft_prcss_percent(ap, i, s);
		}
		i++;
	}
	va_end(ap);
	return (t);
}

int	ft_puthex(unsigned int n, int a)
{
	int		len;
	char	*c;
	int		i;

	len = ft_numb_len(n);
	i = 0;
	c = (char *)malloc((len + 2) * sizeof(char));
	while (n >= 16)
	{
		if (n % 16 < 10)
			c[i++] = (n % 16 + 48);
		else
			c[i++] = (n % 16 + 55);
		n /= 16;
	}
	if (n < 10)
		c[i++] = n + 48;
	else
		c[i++] = n + 55;
	c[i] = '\0';
	ft_strrev(c, a);
	free(c);
	return (ft_check_null(len, 0, 2));
}

int	ft_put_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_prcss_percent(va_list ap, int i, char const *s)
{
	char	c;

	if (s[i] == 'c')
	{
		c = va_arg(ap, int);
		write(1, &c, 1);
		return (1);
	}
	if (s[i] == 'i' || s[i] == 'd')
		return (ft_put_int(va_arg(ap, int)));
	if (s[i] == 'u')
		return (ft_put_unsigned_int(va_arg(ap, int)));
	if (s[i] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (s[i] == 'p' )
		return (ft_punt(va_arg(ap, long)));
	if (s[i] == 'x')
		return (ft_puthex(va_arg(ap, int), 1));
	if (s[i] == 'X')
		return (ft_puthex(va_arg(ap, int), 2));
	if (s[i] == '%')
		return (ft_put_percent());
	return (0);
}
