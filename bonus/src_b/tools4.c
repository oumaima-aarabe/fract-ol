/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:12:14 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/05/02 16:45:59 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_b/fractol.h"

double	interpolate(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

void	applyzoom(t_mlx *m, double mouse_re, double mouse_im, double zoom)
{
	m->min_x = interpolate(mouse_re, m->min_x, zoom);
	m->min_y = interpolate(mouse_im, m->min_y, zoom);
	m->max_x = interpolate(mouse_re, m->max_x, zoom);
	m->max_y = interpolate(mouse_im, m->max_y, zoom);
}

int	mouse_press(int button, int x, int y, t_mlx *m)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom;

	zoom = 1.0;
	mouse_re = (double)x / (WIDTH / (m->max_x - m->min_x)) + m->min_x;
	mouse_im = (double)y / (HEIGHT / (m->max_y - m->min_y)) + m->min_y;
	if (button == 4)
		zoom = 0.9;
	else if (button == 5)
		zoom = 1.1;
	if (button == 4 || button == 5)
		applyzoom(m, mouse_re, mouse_im, zoom);
	start_draw(m);
	return (1);
}
