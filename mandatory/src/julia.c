/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:52:46 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/05/06 19:04:25 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	julia_cal(t_mlx *m, int x, int y)
{
	t_complx	z;
	t_complx	tmp;
	t_complx	c;

	m->iteration = 1;
	z.r = m->min_x + x / (double)WIDTH * (m->max_x - m->min_x);
	z.i = m->min_y + y / (double)HEIGHT * (m->max_y - m->min_y);
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
}

void	ft_julia(t_mlx *m)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			julia_cal(m, x, y);
			if (m->iteration == MAXITER)
				color = 0x00ffff;
			else
				color = 0x00000f * (m->iteration * 70 + 1);
			my_mlx_pixel_put(m, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(m->mlx, m->window, m->img, 0, 0);
}
