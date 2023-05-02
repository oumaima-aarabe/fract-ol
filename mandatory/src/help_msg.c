/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:28:01 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/05/02 16:44:19 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	fractal_options(void)
{
	ft_putendl_fd("+===============  Available Fractals  ===============+", 1);
	ft_putendl_fd("Which fractal would you like to view?", 1);
	ft_putendl_fd("\tMandelbrot", 1);
	ft_putendl_fd("\tjulia", 1);
	ft_putendl_fd("Usage example:\t./fractol <type>\n", 1);
	ft_putendl_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putendl_fd("initial fractal shape. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0 and must contain a decimal point.", 1);
	ft_putendl_fd("Usage example:\t", 1);
	ft_putendl_fd("./fractol julia\n./fractol julia 0.285 0.01", 1);
}

void	print_controls(void)
{
	ft_putendl_fd("\n+===============  Controls  =========================+", 1);
	ft_putendl_fd("scroll wheel\tzoom in and out.", 1);
	ft_putendl_fd("ESC or close window\tquit fractal.", 1);
	ft_putendl_fd("+====================================================+\n", 1);
}

void	help_msg(void)
{
	ft_putendl_fd("\n+====================================================+", 1);
	ft_putendl_fd("|                     FRACT'OL                       |", 1);
	ft_putendl_fd("+====================================================+\n", 1);
	fractal_options();
	print_controls();
}
