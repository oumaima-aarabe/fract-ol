/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:39:55 by ouaarabe          #+#    #+#             */
/*   Updated: 2022/11/16 13:31:50 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_check_p(va_list args, const char c, int *len)
{
	if (c == 'c')
		*len += ft_printchar(va_arg(args, int));
	else if (c == 's')
		*len += ft_printstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		*len += ft_printnum(va_arg(args, int));
	else if (c == 'u')
		*len = ft_printformat(va_arg(args, unsigned int), c, 10, len);
	else if (c == 'x' || c == 'X')
		*len = ft_printformat(va_arg(args, unsigned int), c, 16, len);
	else if (c == 'p')
	{
		*len += ft_printstr("0x");
		*len = ft_printformat(va_arg(args, unsigned long), 'p', 16, len);
	}
	else if (c == '%')
		*len += write(1, "%", 1);
	return (*len);
}

int	ft_eval(const char *format, va_list args, int *len)
{
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
				return (*len);
			*len = ft_check_p(args, *(format + 1), len);
			format++;
		}
		else
		{
			*len += write(1, format, 1);
		}
		format++;
	}
	return (*len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	len = ft_eval(format, args, &len);
	return (len);
}
