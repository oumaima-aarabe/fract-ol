/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:10:06 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/04/29 20:43:10 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_b/fractol.h"

int ft_isdigit(char c) 
{
   return (c >= '0' && c <= '9');
}

int ft_isspace(char c) 
{
   return (c == ' ');
}

double ft_atof(char *s)
{
    double val;
    double power;
    int i;
    int sign;
    
    val = 0.0;
    i = 0;
    sign = 1;
    power = 1.0;
    while (ft_isspace(s[i]))
        i++;
    if (s[i] == '-')
        sign = -1;
    if (s[i] == '+' || s[i] == '-') 
        i++;
    while(ft_isdigit(s[i]))
    {
        val = 10.0 * val + (s[i] - '0');
        i++;
    }
    if (s[i] == '.')
        i++;
     while(ft_isdigit(s[i]))
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
        i++;
    }
    return (sign * val / (power));
}
