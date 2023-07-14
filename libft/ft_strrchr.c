/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:34:59 by vprieto-          #+#    #+#             */
/*   Updated: 2022/10/07 10:43:19 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
		{
			k = i;
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	if (k != -1)
		return ((char *)s + k);
	else
		return (0);
}
