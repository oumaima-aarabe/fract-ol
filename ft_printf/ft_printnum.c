/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 01:57:18 by ouaarabe          #+#    #+#             */
/*   Updated: 2022/11/14 15:48:26 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printnum(long n)
{
	if (n < 0)
	{
		ft_printchar('-');
		n = -n;
		ft_printnum(n);
		return (ft_ln(-n, 10, 'i'));
	}
	if (n >= 10)
	{
		ft_printnum(n / 10);
		ft_printchar(n % 10 + '0');
	}
	if (n <= 9)
		ft_printchar(n + '0');
	return (ft_ln(n, 10, 'i'));
}
