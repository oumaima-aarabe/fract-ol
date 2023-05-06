/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:33:24 by ouaarabe          #+#    #+#             */
/*   Updated: 2023/05/06 00:10:04 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_b/fractol.h"

void	my_mlx_pixel_put(t_mlx *m, int x, int y, int color)
{
	m->addr[y * WIDTH + x] = color;
}

void	start_draw(t_mlx *m)
{
	mlx_destroy_image(m->mlx, m->img);
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	m->addr = (int *)mlx_get_data_addr(m->img, &m->bpp, &m->ll, &m->endian);
	if (m->id == 1)
	{
		ft_mandel(m);
	}
	else if (m->id == 2 || m->id == 3)
		ft_julia(m);
	else if (m->id == 4)
		ft_burning(m);
}

void	ft_draw(t_mlx *m)
{
	m->mlx = mlx_init();
	m->window = mlx_new_window(m->mlx, WIDTH, HEIGHT, "fractal");
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	m->addr = (int *)mlx_get_data_addr(m->img, &m->bpp, &m->ll, &m->endian);
	start_draw(m);
	mlx_hook(m->window, 4, 0, mouse_press, (void *)m);
	mlx_hook(m->window, 17, 0, close_win, (void *)m);
	mlx_hook(m->window, 2, 1L << 0, key_press, (void *)m);
	mlx_loop(m->mlx);
}
