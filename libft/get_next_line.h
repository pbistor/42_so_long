/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:28:00 by vprieto-          #+#    #+#             */
/*   Updated: 2023/07/14 11:27:55 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifdef BUFFER_SIZE
# else
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

char	*read_buffer(char *stc, int fd);
char	*gt_line(char *stc);
char	*move_static(char *stc);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif
