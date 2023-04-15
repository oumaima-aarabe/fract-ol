/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:28:11 by ouaarabe          #+#    #+#             */
/*   Updated: 2022/11/16 11:28:30 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>
# include<stdio.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_printnum(long n);
int		ft_printformat(unsigned long n, char f, unsigned int base, int *len);

size_t	ft_strlen(const	char *s);
size_t	ft_ln(long n, int base, char format);

#endif