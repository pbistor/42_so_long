/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:52:30 by vprieto-          #+#    #+#             */
/*   Updated: 2022/11/04 11:37:20 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_int(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(n);
	while (str[i] != 0)
	{
		write(1, &str[i++], 1);
	}
	free (str);
	return (i);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	int		i;
	char	*str;
	int		len;
	long	num;

	num = n;
	len = ft_unsigned_calclen(n);
	i = 0;
	if (num < 0)
		num *= -1;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	len--;
	while (len >= 0 && str[len] != '-')
	{
		str[len--] += (num % 10) + '0' ;
		num = num / 10;
	}
	return (str);
}

int	ft_put_unsigned_int(unsigned int n)
{
	int				i;
	unsigned int	j;
	char			*str;

	i = 0;
	j = 0;
	if (n < 0)
		j = 4294967274 - n;
	str = ft_unsigned_itoa(n);
	while (str[i] != 0)
	{
		write(1, &str[i++], 1);
	}
	free (str);
	return (i);
}

int	ft_unsigned_calclen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
