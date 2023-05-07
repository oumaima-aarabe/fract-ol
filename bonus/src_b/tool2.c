/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:10:06 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/05/07 21:30:03 by ouaarabe         ###   ########.fr       */
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

double	calcul(char *s, int i)
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
	int			sign;
	int			i;
	double		result;

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

int	num_check(char *str)
{
	size_t	i;
	int		dot_count;

	i = 0;
	dot_count = 0;
	if (str[i + 1] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '.'))
	{
		if (str[i] == '.')
			dot_count++;
		i++;
	}
	if (dot_count != 1 || i != ft_strlen(str))
		return (0);
	else
		return (1);
}
