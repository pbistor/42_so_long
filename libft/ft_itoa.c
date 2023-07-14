/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:16:36 by vprieto-          #+#    #+#             */
/*   Updated: 2022/10/07 10:30:02 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calclen(int n)
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

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		len;
	long	num;

	num = n;
	len = ft_calclen(n);
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
