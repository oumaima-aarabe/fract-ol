/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:24:56 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/05/02 00:58:11 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_b/fractol.h"

void	ft_init(t_mlx *m)
{
	m->max_x = 2;
	m->min_x = -2;
	m->max_y = 2;
	m->min_y = -2;
	m->lr = 0;
	m->ud = 0;
	m->c = 1;
	choose_color(m);
}

void	choose_color(t_mlx *m)
{
	if (m->c == 1)
	{
		if (m->id == 1)
			m->color = 0x0f00d0;
		else if (m->id == 4)
			m->color = 0x0f0000;
		else
			m->color = 0x0f00d0;
	}
	else if (m->c == 2)
	{
		if (m->id == 1)
			m->color = 0xf2f0de;
		else if (m->id == 4)
			m->color = 0x00f0ff;
		else
			m->color = 0x00ffff;
	}
}

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

int	close_win(t_mlx *m)
{
	mlx_destroy_image(m->mlx, m->img);
	mlx_destroy_window(m->mlx, m->window);
	free(m);
	exit(0);
}

int	key_press(int keycode, t_mlx *m)
{
	if (keycode == 53)
		close_win(m);
	else if (keycode == 123)
		m->lr -= 10;
	else if (keycode == 124)
		m->lr += 10;
	else if (keycode == 125)
		m->ud += 10;
	else if (keycode == 126)
		m->ud -= 10;
	else if (keycode == 2)
	{
		m->c = 2;
		choose_color(m);
	}
	else if (keycode == 37)
	{
		m->c = 1;
		choose_color(m);
	}
	start_draw(m);
	return (0);
}
