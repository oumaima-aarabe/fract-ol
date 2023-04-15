/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ln.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:56:20 by ouaarabe          #+#    #+#             */
/*   Updated: 2022/11/16 10:58:03 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

size_t	ft_ln(long n, int base, char format)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0 && format != 'p')
		i = 1;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}
