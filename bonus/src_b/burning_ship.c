/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:52:15 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/04/28 22:59:45 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_b/fractol.h"
#include <stdio.h>

void    ft_burning(t_mlx *m)
{
	t_complx	z;
	t_complx	tmp;
	t_complx	c;
	int		x;
	int 	y;
	int		color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			m->iteration = 1;

			c.r =  m->min_x + (x + m->lr) / (double)WIDTH * (m->max_x - m->min_x);
			c.i =  m->min_y + (y + m->ud) / (double)HEIGHT * (m->max_y - m->min_y);
			z.r = 0.0;
			z.i = 0.0;
			tmp = z;
			while (z.r * z.r + z.i * z.i < 4 && m->iteration < MAXITER)
			{
				tmp.r = fabs(z.r * z.r - z.i * z.i + c.r);
				tmp.i = fabs(2 * z.r * z.i + c.i);
				z = tmp;
				m->iteration++;
			}
			if (m->iteration == MAXITER)
				color = 0x0f0000;
			else
				color = 0x0f0000 * m->iteration;
			my_mlx_pixel_put(m, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(m->mlx, m->window, m->img, 0, 0);
}