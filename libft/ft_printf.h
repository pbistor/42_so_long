/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprieto- <vprieto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:21:18 by vprieto-          #+#    #+#             */
/*   Updated: 2023/07/14 02:09:47 by vprieto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# include <limits.h>

int		ft_printf(char const *s, ...);
int		ft_print_null(void);
int		ft_numb_len(unsigned long long n);
void	ft_strrev(char *str, int a);
int		ft_check_null(int len, int extra, int a);
int		ft_punt(unsigned long long n);
int		ft_puthex(unsigned int n, int a);
int		ft_putstr(char *s);
int		ft_unsigned_calclen(unsigned int n);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_put_unsigned_int( unsigned int n);
int		ft_put_percent(void);
int		ft_prcss_percent(va_list ap, int i, char const *s);
int		ft_put_int(int n);

#endif
