/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:17:47 by vprieto-          #+#    #+#             */
/*   Updated: 2022/10/07 22:30:18 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_mem(int n, char **p)
{
	while (n > 0)
	{
		free(p[n]);
		n--;
	}
	free(p);
}

int	calcwords(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
			k++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	return (k);
}

int	calc_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	return (i);
}

char	*fill_str(const char *s, char c, int j, char **p)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = calc_len(s, c);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		free_mem(j, p);
		return (NULL);
	}
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		wds;
	int		j;
	char	**p;

	j = 0;
	if (!s)
		return (0);
	wds = calcwords(s, c);
	p = (char **)malloc(sizeof(char *) * (wds + 1));
	if (!p)
		return (0);
	while (j < wds)
	{
		while (*s == c)
			s++;
		if (*s != 0)
			p[j] = fill_str(s, c, j, p);
		while (*s != c && *s != 0)
			s++;
		j++;
	}
	p[j] = 0;
	return (p);
}
