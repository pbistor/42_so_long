/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:42:49 by vprieto-          #+#    #+#             */
/*   Updated: 2022/10/07 22:33:36 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	looping(char const *s1, char const *set, int len)
{
	int	i;

	i = 0;
	while (s1[i] != 0)
	{
		if (!ft_isinset(s1[i], set))
		{
			return (i);
		}
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	end;
	int	len;
	int	strt;

	if (!s1)
		return (0);
	i = 0;
	end = 0;
	len = ft_strlen(s1);
	strt = len;
	if (!s1 || !set)
		return (NULL);
	strt = looping(s1, set, len);
	i = len - 1;
	while (i > 0)
	{
		if (!ft_isinset(s1[i], set))
		{
			end = i;
			break ;
		}
		i--;
	}
	return (ft_substr(s1, strt, end - strt + 1));
}
