/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_punt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:01:06 by vprieto-          #+#    #+#             */
/*   Updated: 2022/11/04 11:41:14 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_punt(unsigned long long n)
{
	int		len;
	char	*c;
	int		i;

	len = ft_numb_len(n);
	i = 0;
	c = (char *)malloc((len + 2) * sizeof(char));
	write(1, "0x", 2);
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
	ft_strrev(c, 1);
	free(c);
	return (ft_check_null(len, 2, 1));
}

int	ft_numb_len(unsigned long long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_strrev(char *str, int a)
{
	int	len;

	len = ft_strlen(str);
	len--;
	while (len >= 0)
	{
		if (str[len] >= 'A' && str[len] <= 'Z' & a == 1)
			str[len] = str[len] + 32;
		write(1, &str[len--], 1);
	}
}

int	ft_check_null(int len, int extra, int a)
{
	if (len == 0)
		return (1 + extra);
	else
	{
		if (a == 1)
			return (len + 2);
		if (a == 2)
			return (len);
	}
	return (0);
}
