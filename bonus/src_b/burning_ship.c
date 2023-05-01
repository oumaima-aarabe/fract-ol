/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:52:15 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/05/02 00:38:49 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_b/fractol.h"
#include <stdio.h>

void	burning_cal(t_mlx *m, int x, int y)
{
	t_complx	z;
	t_complx	tmp;
	t_complx	c;

	m->iteration = 1;
	c.r = m->min_x + (x + m->lr) / (double)WIDTH * (m->max_x - m->min_x);
	c.i = m->min_y + (y + m->ud) / (double)HEIGHT * (m->max_y - m->min_y);
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
}

void	b_coloring(t_mlx *m, int *color)
{
	if (m->c == 1)
	{
		if (m->iteration == MAXITER)
			*color = m->color;
		else
			*color = m->color * m->iteration;
	}
	else if (m->c == 2)
	{
		if (m->iteration == MAXITER)
			*color = m->color;
		else
			*color = m->color * m->iteration;
	}
}

void	ft_burning(t_mlx *m)
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
			burning_cal(m, x, y);
			b_coloring(m, &color);
			my_mlx_pixel_put(m, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(m->mlx, m->window, m->img, 0, 0);
}
