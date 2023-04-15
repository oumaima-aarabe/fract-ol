/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:04:01 by ouaarabe          #+#    #+#             */
/*   Updated: 2022/11/16 13:04:00 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printformat(unsigned long n, char f, unsigned int base, int *len)
{
	if (n == 0)
	{
		*len += ft_printchar(48);
		return (*len);
	}
	if (n >= base)
	{
		ft_printformat(n / base, f, base, len);
		ft_printformat(n % base, f, base, len);
	}
	else if (n > 9 && n < base)
	{
		if (f == 'x' || f == 'p')
			*len += ft_printchar(n - 10 + 'a');
		else
			*len += ft_printchar(n - 10 + 'A');
	}
	else if (n <= 9 && n != 0)
		*len += ft_printchar(n + 48);
	return (*len);
}
