/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:52:46 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/04/29 20:42:20 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_b/fractol.h"

void    ft_julia(t_mlx *m)
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

			z.r =  m->min_x + (x + m->lr) / (double)WIDTH * (m->max_x - m->min_x);
			z.i =  m->min_y + (y + m->ud) / (double)HEIGHT * (m->max_y - m->min_y);
			if (m->id == 3)
			{
				c.r = m->r;
				c.i = m->i;
			}
			else
			{
				c.r = PR;
				c.i = PI;
			}
			tmp = z;
			while (z.r * z.r + z.i * z.i < 4 && m->iteration < MAXITER)
			{
				tmp.r = z.r * z.r - z.i * z.i + c.r;
				tmp.i = 2 * z.r * z.i + c.i;
				z = tmp;
				m->iteration++;
			}
			if (m->c == 1)
			{
				if (m->iteration == MAXITER)
					color = m->color;
				else
				color = m->color * m->iteration;
			}
			else if (m->c == 2)
			{
				if (m->iteration == MAXITER)
					color = m->color;
				else
					color = m->color * (m->iteration * 70 + 1);
			}
			my_mlx_pixel_put(m, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(m->mlx, m->window, m->img, 0, 0);
}
