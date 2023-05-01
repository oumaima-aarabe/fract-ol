/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:10:06 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/05/02 00:43:23 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_b/fractol.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(char c)
{
	return (c == ' ');
}

int	calcul(char *s, int i)
{	
	double	val;
	double	power;

	val = 0.0;
	power = 1.0;
	while (ft_isdigit(s[i]))
	{
		val = 10.0 * val + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
		i++;
	}
	return (val / power);
}

double	ft_atof(char *s)
{
	int		sign;
	int		i;
	int		result;

	i = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	result = calcul(s, i);
	return (sign * result);
}
