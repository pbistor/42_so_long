/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:00:57 by vprieto-          #+#    #+#             */
/*   Updated: 2023/07/14 10:47:25 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stc;
	char		*aux;

	if (((read(fd, 0, 0) < 0) || fd < 0 || BUFFER_SIZE <= 0))
	{
		if (stc != NULL)
		{
			free(stc);
			stc = NULL;
		}
		return (NULL);
	}
	stc = read_buffer(stc, fd);
	if (!stc)
		return (NULL);
	aux = gt_line(stc);
	if (aux == NULL)
	{
		free(stc);
		stc = NULL;
		return (NULL);
	}
	stc = move_static(stc);
	return (aux);
}

char	*gt_line(char *stc)
{
	int		i;
	char	*temp;

	i = 0;
	while (stc[i] != '\n' && stc[i] != '\0')
		i++;
	temp = ft_calloc(i + 2, 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (stc[i] != '\n' && stc[i] != '\0')
	{
		temp[i] = stc[i];
		i++;
	}
	if (stc[i] == '\n')
		temp[i] = stc[i];
	else if (stc[i] == '\0' && temp[0] == '\0')
	{
		free(temp);
		return (NULL);
	}
	temp[++i] = '\0';
	return (temp);
}

char	*move_static(char *stc)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (stc[i] != '\n' && stc[i] != '\0')
	{
		i++;
	}
	temp = ft_calloc(ft_strlen(stc) - i + 1, 1);
	if (!temp)
		return (NULL);
	if (stc[i] == '\n')
		i++;
	while (stc[i] != '\0' )
	{
		temp[j++] = stc[i];
		i++;
	}
	free(stc);
	return (temp);
}

char	*add_stc(char *stc, char *aux)
{	
	unsigned int	i;
	unsigned int	len;

	aux = ft_calloc(1, sizeof(char));
	if (!aux)
		return (NULL);
	i = 0;
	if (stc != NULL)
	{
		len = ft_strlen(stc);
		free(aux);
		aux = ft_calloc(len + 1, 1);
		if (!aux)
			return (NULL);
		while (i < len)
		{
			aux[i] = stc[i];
			i++;
		}
	}
	return (aux);
}

char	*read_buffer(char *stc, int fd)
{
	char			*temp;
	int				bread;
	char			*aux;

	aux = NULL;
	bread = 1;
	aux = add_stc(stc, aux);
	free(stc);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while ((bread > 0 && !ft_strchr(aux, '\n')))
	{
		bread = read(fd, temp, BUFFER_SIZE);
		aux = ft_strjoin(aux, temp);
		if (ft_strchr(temp, '\n'))
			break ;
		free(temp);
		temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!temp)
			return (NULL);
	}
	free(temp);
	return (aux);
}
